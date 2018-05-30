#include "StdAfx.h"
#include "VisionMatch.h" 

VisionMatch::VisionMatch(void)
{
	this->target = NULL ;
	this->coeff = NULL ;

	this->initData();
}

void VisionMatch::initData() {

	release();

	this->target = NULL ;
	this->coeff = NULL ;

	this->mousePressedX = -1 ;
	this->mousePressedY = -1 ;

	this->roiPreCenterX = -1 ;
	this->roiPreCenterY = -1 ;

	this->buildTarget = true ;
	this->targetBuildCnt = 0 ; 

	this->msg = ""; 
} 

VisionMatch::~VisionMatch(void)
{
	release();
}

bool VisionMatch::preProcessImage(VisionOptionInterface^ vi, Mat * grayImg  )
{
	// preProcess

	Mat * src = grayImg ; 

	// gaussian blurring
	Mat blur ;
	if( vi->isPreGaussianBlur() ) { 
		int kSize = vi->getPreGuassianBlurKSize() ;		
		kSize = kSize < 0 ? 0 : kSize ;
		if( kSize%2 == 0 ) {
			// kSize should be an odd positive integer
			kSize += 1;
		}
		GaussianBlur( * src, blur, Size( kSize,kSize ), 1.5, 1.5); 

		src = & blur ; 
	}

	// histogram equalization
	Mat hist ;
	if( vi->isPreHistEqualize() ) {
		cv::equalizeHist( * src, hist );

		src = & hist;
	}

	// adaptive threshold
	Mat adap ; 
	if( vi->isPreAdaptiveThreshold() ) {
		int bSize = vi->getPreAdaptiveThresholdBSize();
		cv::adaptiveThreshold( *src, adap, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, bSize, 0 );

		src = & adap ;
	}

	// binarization
	Mat bin ; 
	if( vi->isPreBinary() ) {
		int thresh = vi->getPreBinaryThreshold();
		cv::threshold( *src, bin, thresh, 255, cv::THRESH_BINARY ) ; 
		src = & bin;
	}  

	CannyOption * cannyOption = vi->getPreCannyOption();
	Mat canny ; 

	if( cannyOption->isCanny ) {
		// canny edge
		int apertureSize = cannyOption->apertureSize; //// size of the extended Sobel kernel; it must be 1, 3, 5, or 7.
		apertureSize = apertureSize > 7 ? 7 : apertureSize ;
		apertureSize = apertureSize < 0 ? 1 : apertureSize ;
		if( apertureSize%2 == 0 ) {
			// apertureSize is an odd integer.
			apertureSize += 1;
		}
		Canny( * src, canny, 0, cannyOption->threshold_02, apertureSize, true );

		src = & canny ; 
	}  

	if( src != grayImg ) {
		src->copyTo( * grayImg  );
	} 

	// end of pre process

	return true;
}

bool VisionMatch::postProcessImage( VisionOptionInterface^ vi, Mat * srcImg, Mat * outImg )
{
	return true;
}

bool VisionMatch::processImage( VisionOptionInterface^ vi, Mat * srcImg, Mat * outImg , VideoInfo * videoInfo )
{ 
	const int width = srcImg->cols ;
	const int height = srcImg->rows ;

	bool roiFixed = imageRoi.fixed;
	bool targetFixed = targetRoi.fixed ;

	if( ! roiFixed || ! targetFixed ) {
		bool showMsg = false ; 
		if( showMsg ) { 
			msg = "set the ROI by double-clicking, please!" ; 
		}

		if( NULL != target ) {
			target->release();

			delete target ;
			target = NULL ; 
		}

		target = NULL ; 
		buildTarget = true ;

		Roi * roi = & this->imageRoi; 

		if( roi->GetRect()->area() < 1 ) { 
			roi->leftTop.x = width/4 ;
			roi->leftTop.y = height/4 ;
			roi->rightBottom.x = width*3/4 ;
			roi->rightBottom.y = height*3/4 ; 

			roi->InValidte(); 
			roi->UnSelected();

			roi->selected = true;
		}

		roi = & this->targetRoi ; 

		if( roi->GetRect()->area() < 1 ) {    
			cv::Rect * rect = imageRoi.GetRect(); 

			int x = rect->x ;
			int y = rect->y ;
			int w = rect->width ;
			int h = rect->height ;

			roi->leftTop.x = x + w/4 ;
			roi->leftTop.y = y + h/4 ;
			roi->rightBottom.x = x + w*3/4 ;
			roi->rightBottom.y = y + h*3/4 ; 

			roi->InValidte();
			roi->UnSelected();
		}
	}

	bool preProcess = roiFixed && targetFixed ;  

	bool matchTemplate = false;

	if( ! preProcess ) { 
		srcImg->copyTo( * outImg ); 
	} else if( preProcess ) {    
		srcImg->copyTo( * outImg ); 

		cv::Rect * roiRect = imageRoi.GetRect(); 

		Mat outImgRoi = (*outImg)( * roiRect );

		// pre process
		Mat grayImg ;

		// convert the src image to a gray scale image
		cv::cvtColor( outImgRoi , grayImg , CV_BGR2GRAY ); 

		this->preProcessImage( vi, & grayImg ) ;
		// end of pre process

		// build target
		if( buildTarget || NULL == target ) { 

			buildTarget = false ; 
			target = new Mat( ); 
			targetBuildCnt ++ ;

			cv::Rect * targetRect = targetRoi.GetRect();

			int x = targetRect->x - roiRect->x;
			int y = targetRect->y - roiRect->y;

			int w = targetRect->width;
			int h = targetRect->height;

			Rect rectSub( x, y, w, h );

			Mat targetTemp = (grayImg)( rectSub ) ;  

			targetTemp.copyTo( * target );

			targetTemp.release();

			if( true ) {  
				targetColorImg.release();

				Mat temp = (* srcImg)( * targetRoi.GetRect() ) ; 

				temp.copyTo( targetColorImg );

				temp.release(); 

				RECT targetVideoRect ; 
				bool b = vi->SetTargetPbImage( this, & targetVideoRect, & targetColorImg );
			}

			if( NULL != coeff ) {
				coeff->release();
				delete coeff;
				coeff = NULL;
			}

			coeff = new Mat( );  

			vi->showMsg( "^^ Rebuilding template target. [ " + targetBuildCnt + " ]");
		}   
		// end of building target

		// template matching

		// CV_TM_CCORR == DIC 알고리즘 
		// CV_TM_CCORR_NORMED == NCC 알고리즘

		const int match_method = vi->getMatchMethod();
		cv::matchTemplate( grayImg, * target,  * coeff, match_method);

		if( vi->isCoeffNorm() ) { 
			cv::normalize( * coeff,  * coeff, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());		
		}

		bool debug = false; 
		
		if( debug ) { 
			cv::imshow( "coeff", * coeff );
		}

		MatchResult matchResult ;

		cv::minMaxLoc( * coeff, & matchResult.minVal, & matchResult.maxVal, & matchResult.minLoc, & matchResult.maxLoc );

		matchResult.matchLoc = & matchResult.maxLoc ;  

		matchResult.toLoc.x = matchResult.matchLoc->x + target->cols ;
		matchResult.toLoc.y = matchResult.matchLoc->y + target->rows ; 

		// match processing time
		const int fps = videoInfo->fps ; 
		const int prcsFrameCnt = videoInfo->prcsFrameCnt ; 
		const long prcsTimeMiliSec  = (long) ( prcsFrameCnt/(fps + 0.0)*1000 );

		matchResult.AdjustToRoi( prcsTimeMiliSec, & this->imageRoi, & this->targetRoi , vi->GetScaleFactor() );

		// end of template matching

		// copy gray scale image on the out image
		cv::cvtColor( grayImg, outImgRoi, cv::COLOR_GRAY2RGB ); 

		grayImg.release();

		// draw image roi only, don't draw the target roi when preprocess is true
		imageRoi.simpleRect = false ;
		targetRoi.simpleRect = true ;
		this->drawRoiAndTarget( outImg, & imageRoi, &targetRoi ); 

		// draw match info on the output image

		this->drawMatchInfoOnImage( outImg, & matchResult, vi );

		vi->ProcessMatchResult( & matchResult, videoInfo );

		matchTemplate = true;
	}	

	if( msg.length() > 0 ) {
		// draw message on the image

		Mat * img = outImg ;

		Scalar * textColor = & BLUE ;

		double fontScale = 0.7 ; // 0.5

		this->showMsgOnImage( & this->msg, textColor, fontScale, img );

		vi->showMsg( & msg );

		this->msg = "" ;
	}

	// end of drawing matching info on the image.

	if( false == preProcess ) { 
		// draw the image roi and target roi when pre process false 
		imageRoi.simpleRect = false ;
		targetRoi.simpleRect = false ;
		this->drawRoiAndTarget( outImg, & imageRoi, & targetRoi ); 
	}

	return matchTemplate ;

}

void VisionMatch::drawRoiAndTarget( Mat * img, Roi * imageRoi, Roi * targetRoi ) {

	// draw match rectangle 

	cv::Rect * rect ;
	ShapeStyle shapeStyle;
	shapeStyle.fillColor = WHITE ;

	shapeStyle.thickness = 1;  

	// draw the image ROI 
	Roi * roi = imageRoi;

	int m = 6; 

	if( NULL != roi ) {  
		shapeStyle.showTick = ! roi->fixed ;

		if( roi->fixed ) {
			shapeStyle.lineColor = GREEN ; 
		} else {
			shapeStyle.lineColor = HEX_HOTPINK_FF69B4 ;
		}

		rect = roi->GetRect();

		if( roi->simpleRect ) {  
			this->drawSimpleRect( img, rect, & shapeStyle ); 
		} else { 
			this->drawDecoRect( img, rect, & shapeStyle ); 
		}
	}

	// draw the target ROI
	roi = targetRoi;

	if( NULL != roi ) { 
		shapeStyle.showTick = ! roi->fixed ;
		shapeStyle.drawCenterCross = true ; 

		if( roi->fixed ) {
			shapeStyle.lineColor = GREEN ; 
		} else {
			shapeStyle.lineColor = RED ;
		}

		rect = roi->GetRect();

		if( roi->simpleRect ) {
			this->drawSimpleRect( img, rect, & shapeStyle ); 
		} else {
			this->drawDecoRect( img, rect, & shapeStyle ); 
		}
		
	}
}

void VisionMatch::drawMatchInfoOnImage( Mat * img, MatchResult * matchResult, VisionOptionInterface^ vi ) {
	// drawing matching info on the out put image 

	cv::Point * matchLoc = matchResult->matchLoc ;
	cv::Point * toLoc  = & matchResult->toLoc ;

	cv::Point * minLoc = & matchResult->minLoc ;
	cv::Point * maxLoc = & matchResult->maxLoc ;

	double minVal = matchResult->minVal ;
	double maxVal = matchResult->maxVal ;

	cv::Point matchCenter( ( matchLoc->x + toLoc->x )/2 , ( matchLoc->y + toLoc->y )/2 ) ;

	// draw match rectangle
	Scalar * color = & YELLOW ; 
	cv::rectangle( * img, * matchLoc, * toLoc , * color, 2); 

	int radius = 6 ;

	if( true ) { 
		// draw location as a circle

		Scalar * fillColor = & GRAY_144 ;  
		Scalar * circleColor = & RED ; 

		cv::Point * center;

		// draw minLoc or maxLoc
		center = minLoc ;
		circleColor = & BLUE ;  
		if( center == matchLoc ) {
			center = maxLoc ;
			circleColor = & RED ;
			fillColor = & WHITE ; 
			if( vi->showMatchMaxValue() ) {  
				this->drawCircle( img, center, radius, fillColor, circleColor );
			}
		} else if( vi->showMatchMinValue() ) { 
			fillColor = & WHITE ; 
			this->drawCircle( img, center, radius, fillColor, circleColor );
		} 

		if( vi->showMatchMaxValue() ) {   
			// draw match loc circle
			center = matchLoc ; 
			fillColor = & WHITE ; 
			this->drawCircle( img, center, radius, fillColor, circleColor ); 
		}

		bool showMatchLoc = false ;

		if( showMatchLoc ) { 
			// draw toLoc circle
			center = toLoc ;
			circleColor = & YELLOW ; 
			fillColor = & WHITE ; 
			this->drawCircle( img, center, radius, fillColor, circleColor ); 
		}

	}

	Scalar textColor = BLUE ;	
	Scalar fillColor = Vision::WHITE ;  

	char text[100];

	int m = 2;

	if( vi->showMatchMinValue() ) { 
		// draw min value 
		textColor = BLUE ;
		sprintf_s( text, "min: [%.3f]", minVal );

		cv::Point * loc = minLoc ; 
		int hAlign =  0 ;
		int vAlign =  1 ;

		int tx = loc->x + radius*2 + m;
		int ty = loc->y;

		if( false ) { 
			tx = tx < 0 ? 0 : tx;
			ty = ty < 20 ? 20 : ty ; 
		}

		cv::Point textOrg( tx, ty ); 

		FontStyle fontStyle;
		fontStyle.fillColor = fillColor ;
		fontStyle.textColor = textColor ;
		fontStyle.fontScale = 0.5;
		fontStyle.hAlign = hAlign;
		fontStyle.vAlign = vAlign;

		this->drawText( img, text, & textOrg, & fontStyle );
	} 

	if( vi->showMatchMaxValue() ) { 
		// draw max value
		textColor = RED ;
		sprintf_s( text, "max: [%.3f]", maxVal );

		cv::Point * loc = maxLoc ; 
		int hAlign = 0 ;
		int vAlign = 1 ;

		int tx = loc->x + radius*2 + m ;
		int ty = loc->y;

		if( false ) { 
			tx = tx < 0 ? 0 : tx;
			ty = ty < 20 ? 20 : ty ; 
		} 

		cv::Point textOrg( tx, ty ); 

		FontStyle fontStyle;
		fontStyle.fillColor = fillColor ;
		fontStyle.textColor = textColor ;
		fontStyle.fontScale = 0.5;
		fontStyle.hAlign = hAlign;
		fontStyle.vAlign = vAlign;

		this->drawText( img, text, & textOrg, & fontStyle ); 
	}  

	// draw the displacement info
	if( true ) {
		Disp * disp = matchResult->GetDisp();

		const double dx = disp->GetDxPixel();
		const double dy = disp->GetDyPixel() ; 

		cv::Point * tCenter = this->targetRoi.GetCenter();

		// draw center cross 
		bool drawTargetCenterCross = true ; 
		if( drawTargetCenterCross ) {
			ShapeStyle shapeStyle ;
			shapeStyle.fillColor = BLUE ;
			shapeStyle.lineColor = YELLOW ;
			shapeStyle.thickness = 2;

			this->drawCross( img, tCenter, 6, & shapeStyle );
		} 

		ShapeStyle shapeStyle;
		shapeStyle.thickness = 1 ;
		shapeStyle.lineType = 8 ;
		shapeStyle.lineColor = RED ;
		shapeStyle.fillColor = YELLOW ;   

		FontStyle fontStyle;
		fontStyle.fillColor = fillColor ;
		fontStyle.textColor = textColor ;
		fontStyle.fontScale = 0.5; 

		if( false ) { 
			// draw dx displacement
			double x = tCenter->x + dx ;
			double y = tCenter->y ; 

			cv::Point p( tCenter->x, tCenter->y ); 
			cv::Point q( (int)(x + 0.5), (int)(y + 0.5) );

			this->drawLine( img, & p, & q, & shapeStyle ); 
		}

		if( false ) { 
			// draw dy displacement
			double x = tCenter->x + dx ;
			double y = tCenter->y + dy ; 

			cv::Point p( (int)(x + 0.5), tCenter->y );
			cv::Point q( (int)(x + 0.5), (int)(y + 0.5) ); 

			this->drawLine( img, & p, & q, & shapeStyle );  
		}

		if( true ) { 
			// draw dx and dy displacement
			double x = tCenter->x + dx ;
			double y = tCenter->y + dy ; 

			cv::Point p( tCenter->x , tCenter->y );
			cv::Point q( (int)(x + 0.5), (int)(y + 0.5) ); 

			shapeStyle.lineType = CV_AA ; 
			shapeStyle.tipLength = 0.1 ;

			this->drawLine( img, & p, & q, & shapeStyle ); 

			shapeStyle.tipLength = 0;
		}

		if( vi->isShowPrcsInfoOnImage() ) { 
			// draw dx dy text info  

			sprintf_s( text, "dX: %+05d; dY: %+05d", (int) dx, (int) dy );

			cv::Size textSize = this->getTextSize( text, & fontStyle );

			int m = 20 ; 
			int tx = (int) ( tCenter->x + dx );
			int ty = (int) ( tCenter->y + dy );

			int hAlign = 0 ;
			int vAlign = 1 ; 

			if( dx >= 0 ) {
				tx += m ; 
			} else if( dx < 0 ){
				tx = tCenter->x + m ; 
			} 

			cv::Point textOrg( tx, ty );

			fontStyle.hAlign = hAlign ;
			fontStyle.vAlign = vAlign  ;

			this->drawText( img, text, & textOrg, & fontStyle ); 
		}
	}

	// end of drawing the displacement info

	// draw center cross 
	bool drawMatchCenterCross = false ; 
	if( drawMatchCenterCross ) {
		ShapeStyle shapeStyle ;
		shapeStyle.fillColor = BLUE ;
		shapeStyle.lineColor = YELLOW ;
		shapeStyle.thickness = 2;

		this->drawCross( img, & matchCenter, 6, & shapeStyle );
	} 
	
}

void VisionMatch::showMsgOnImage( cv::String * msg, Scalar * textColor, double fontScale, Mat * img ) {
	// draw message on the image

	Scalar * fillColor = & GRAY_144 ; 
	int hAlign =  1 ;
	int vAlign =  1 ;

	int width = img->cols ;
	int height = img->rows ; 

	const char * text = msg->c_str();

	int fontFace = CV_FONT_HERSHEY_COMPLEX; // FONT_HERSHEY_PLAIN;;

	int thickness = 1 ; 
	cv::Size textSize = cv::getTextSize( text, fontFace, fontScale, thickness, 0); 

	const int tx = width/2 - textSize.width/2 ;
	const int ty = height - textSize.height - textSize.height/2 ;

	if( NULL != fillColor ) { 

		const int tm = textSize.height/2;

		const int x = tx - tm;
		const int y = ty - textSize.height - tm;

		const int w = textSize.width + 2*tm ;
		const int h = textSize.height + 2*tm ;

		if( true ) {  
			int m = 2 ;
			cv::Point from( x - m, y - m );
			cv::Point to( x + w + 2*m - 1, y + h + 2*m - 1 );

			cv::rectangle( * img, from, to, * fillColor, 2 ); 
		}

		if( true ) {  
			int m = 1;
			cv::Point from( x - m, y - m );
			cv::Point to( x + w + 2*m, y + h + 2*m );

			cv::rectangle( * img, from, to, BLACK , 1); 
		}

		if( true ) {  
			int m = 0;
			cv::Point from( x - m, y - m );
			cv::Point to( x + w + 2*m + 1, y + h + 2*m + 1 );

			cv::rectangle( * img, from, to, * fillColor, -1); 
		}

	}

	Point textOrg( tx, ty ); 

	Scalar * color ;
	bool showBgWhite = true  ;

	int lineType = 8; // CV_AA ; // CV_AA ;
	// 8 (or omitted) - 8-connected line.
	// 4 - 4-connected line.
	// CV_AA - anti aliased line.

	if( showBgWhite ) { 
		color = & GRAY_200  ;
		thickness = 5 ; 
		lineType = CV_AA;

		putText( *img, text, textOrg, fontFace, fontScale, * color, thickness, lineType );
	}

	if( showBgWhite ) { 
		color = & WHITE  ;
		thickness = 3 ; 
		lineType = 8 ;

		putText( *img, text, textOrg, fontFace, fontScale, * color, thickness, lineType );
	}

	color = textColor ;
	thickness = 1;
	lineType = 8 ;

	cv::putText( *img, text, textOrg, fontFace, fontScale, * color, thickness, lineType ); 

}

String VisionMatch::toString()
{
	return "Match";
}

void VisionMatch::setTarget(Mat * target)
{
	release();

	this->target = target;
}

void VisionMatch::release()
{
	if( NULL != this->target ) {
		target->release() ; 
		delete target ;
		target = NULL ;
	} 

	if( NULL != coeff ) {
		coeff->release() ; 
		delete coeff ; 
		coeff = NULL ;
	}
}

void VisionMatch::RebuildTarget()
{
	this->buildTarget = true ;  
}

int VisionMatch::OnMouseEvent( MouseEvent event, int x, int y, VisionOptionInterface^ vi )
{
	int repaint = 0 ;

	bool debug = false;

	if( debug ) {  
		const int buffSize = 100 ;
		char buff[ buffSize ] ;

		sprintf_s( buff, buffSize, "mouse event type:%d ; x: %d; y: %d;", (int) event, x, y );

		vi->showMsg( buff ) ;
	}

	const int minDistum = 36; 

	System::Windows::Forms::PictureBox^ pbVideo = vi->getPbVideo();

	System::Windows::Forms::Cursor^ cursor = nullptr ;

	if( MouseEvent::MOVE == event ) {
		// when mouse move
		bool fixed = this->imageRoi.fixed && this->targetRoi.fixed; 
		if( ! fixed ) { 
			Roi * roi = & this->targetRoi ; 

			if( roi->leftTop.IsSelected( x, y, minDistum ) ) {
				cursor = System::Windows::Forms::Cursors::SizeNWSE ; 
			} else if( roi->rightBottom.IsSelected( x, y, minDistum )) { 
				cursor = System::Windows::Forms::Cursors::SizeNWSE ; 
			} else if( roi->IsSelected( x, y ) ) { 
				cursor = System::Windows::Forms::Cursors::Hand ;  
			}  else {
				roi = & this->imageRoi ;

				if( roi->leftTop.IsSelected( x, y, minDistum ) ) {
					cursor = System::Windows::Forms::Cursors::SizeNWSE ; 
				} else if( roi->rightBottom.IsSelected( x, y, minDistum ) ) { 
					cursor = System::Windows::Forms::Cursors::SizeNWSE ; 
				} else if( roi->IsSelected(x, y) ){ 
					ViPoint * center = roi->GetCenter();

					this->roiPreCenterX = center->x;
					this->roiPreCenterY = center->y;

					cursor = System::Windows::Forms::Cursors::Hand ; 
				} else {
					cursor = System::Windows::Forms::Cursors::Default ;
				}
			} 
		} else {
			cursor = System::Windows::Forms::Cursors::Default ;
		}
		// end of when mouse move
	} else if( MouseEvent::DOWN == event ) {  
		bool fixed = this->imageRoi.fixed && this->targetRoi.fixed; 

		if( ! fixed ) {
			// when roi is not fixed
			this->imageRoi.UnSelected();
			this->imageRoi.InValidte();
			this->targetRoi.UnSelected();
			this->targetRoi.InValidte(); 

			this->mousePressedX = x ;
			this->mousePressedY = y ;

			this->roiPreCenterX = -1 ;
			this->roiPreCenterY = -1 ;

			Roi * roi = & this->targetRoi ; 

			if( roi->leftTop.IsSelected( x, y, minDistum ) ) {
				cursor = System::Windows::Forms::Cursors::SizeNWSE ;
				vi->showMsg( "target roi leftTop selected" );
			} else if( roi->rightBottom.IsSelected( x, y, minDistum )) { 
				cursor = System::Windows::Forms::Cursors::SizeNWSE ;
				vi->showMsg( "target roi rightBottom selected" );
			} else if( roi->IsSelected( x, y ) ) { 
				cursor = System::Windows::Forms::Cursors::Hand ;

				ViPoint * center = roi->GetCenter();

				this->roiPreCenterX = center->x;
				this->roiPreCenterY = center->y;

				vi->showMsg( "target roi selected" ); 
			}  else {
				roi = & this->imageRoi ;

				if( roi->leftTop.IsSelected( x, y, minDistum ) ) {
					cursor = System::Windows::Forms::Cursors::SizeNWSE ;
					vi->showMsg( "image roi leftTop selected" );
				} else if( roi->rightBottom.IsSelected( x, y, minDistum ) ) { 
					cursor = System::Windows::Forms::Cursors::SizeNWSE ;
					vi->showMsg( "image roi rightBottm selected" );
				} else if( roi->IsSelected(x, y) ){ 
					ViPoint * center = roi->GetCenter();

					this->roiPreCenterX = center->x;
					this->roiPreCenterY = center->y;

					cursor = System::Windows::Forms::Cursors::Hand ;

					vi->showMsg( "image roi selected" );  
				} else {
					cursor = System::Windows::Forms::Cursors::Default ;
				}
			} 
			// end of when roi is not fixed
		}

	} else if( MouseEvent::DRAG == event || MouseEvent::UP == event ) {  
		// when mouse drag or mouse up

		bool fixed = this->imageRoi.fixed && this->targetRoi.fixed;  
		if( ! fixed ) { 
			ViPoint * selPoint = NULL ; 
			Roi * selRoi = NULL ; 

			Roi * roi = & this->targetRoi ;
			// set which roi and point is selected when mouse pressed
			if( false == roi->fixed ) {  
				if( roi->selected ) {
					selRoi = roi; 
				}

				if( roi->leftTop.selected ) {
					selPoint = & roi->leftTop ; 
					selRoi = roi ;
				} else if( roi->rightBottom.selected ) {
					selPoint = & roi->rightBottom;
					selRoi = roi ;
				}
			} 

			if( NULL == selRoi && NULL == selPoint ) {  
				roi = & this->imageRoi ;

				if( roi->selected ) {
					selRoi = roi; 
				}

				if( roi->leftTop.selected ) {
					selPoint = & roi->leftTop ; 
					selRoi = roi ;
				} else if( roi->rightBottom.selected ) {
					selPoint = & roi->rightBottom;
					selRoi = roi ;
				}
			}
			// end of set which roi and point is selected when mouse pressed

			if( NULL != selPoint && NULL != selRoi ) { 
				// when a point and a roi is selected

				if( selRoi == & this->imageRoi ) {  
					if( selPoint == & this->imageRoi.leftTop ) {
						// image roi left top position cannot be larger than the one of the target roi 
						cv::Rect * rect = this->targetRoi.GetRect(); 

						int maxX = rect->x ;
						int maxY = rect->y ; 

						int tx = x;
						int ty = y;

						tx = maxX < tx ? maxX : tx;
						ty = maxY < ty ? maxY : ty;

						selPoint->x = tx;
						selPoint->y = ty; 
					} else if( selPoint == & this->imageRoi.rightBottom ) {
						// image roi right bottom position cannot be small than the one of the target roi 
						cv::Rect * rect = this->targetRoi.GetRect(); 

						int minX = rect->x + rect->width ;
						int minY = rect->y + rect->height ; 

						int tx = x;
						int ty = y;

						tx = minX < tx ? tx : minX ;
						ty = minY < ty ? ty : minY ;

						selPoint->x = tx;
						selPoint->y = ty;
					} 
				} else if( selRoi == & this->targetRoi ) {
					// target region cannot larger than the image roi
					cv::Rect * rect = this->imageRoi.GetRect();

					int minX = rect->x;
					int minY = rect->y;

					int maxX = minX + rect->width;
					int maxY = minY + rect->height;

					if( selPoint == & this->targetRoi.leftTop ) {
						// left top position cannot be larger than the right bottom one
						int m = 10; // margin
						maxX = this->targetRoi.rightBottom.x - m ;
						maxY = this->targetRoi.rightBottom.y - m ;
					} else if( selPoint == & this->targetRoi.rightBottom ) {
						// right bottom position cannot be small than the left top one
						int m = 10; // margin
						minX = this->targetRoi.leftTop.x + m;
						minY = this->targetRoi.leftTop.y + m;
					}

					int tx = x;
					tx = minX < tx ? tx : minX ;
					tx = maxX < tx ? maxX : tx;

					int ty = y;
					ty = minY < ty ? ty : minY ;
					ty = maxY < ty ? maxY : ty ;

					selPoint->x = tx;
					selPoint->y = ty;
				}

				selRoi->InValidte();

				repaint = 1;

			} else if( NULL != selRoi && NULL == selPoint ) {
				// when one roi selected and a point is not selected

				if( this->mousePressedX > -1 && this->mousePressedY > -1 && this->roiPreCenterX > -1 && this->roiPreCenterY > -1 ) {  
					int dx = x - this->mousePressedX ;
					int dy = y - this->mousePressedY ; 
				 
					int cx = this->roiPreCenterX + dx;
					int cy = this->roiPreCenterY + dy;

					if( (& this->targetRoi) == selRoi ) {
						// when target roi is selected
						cv::Rect * trr = this->targetRoi.GetRect(); // target roi rect
						cv::Rect * irr = this->imageRoi.GetRect(); // image roi rect

						int minX = irr->x + trr->width/2;
						int minY = irr->y + trr->height/2;

						int maxX = irr->x + irr->width - trr->width/2 ;
						int maxY = irr->y + irr->height - trr->height/2 ;

						cx = minX < cx ? cx : minX ;
						cy = minY < cy ? cy : minY ;

						cx = maxX < cx ? maxX : cx ;
						cy = maxY < cy ? maxY : cy ;
					} else if( (& this->imageRoi) == selRoi ) {
						// when image roi is selected

						ViPoint * tCen = this->targetRoi.GetCenter(); // target roi center

						cv::Rect * trr = this->targetRoi.GetRect(); // target roi rect
						cv::Rect * irr = this->imageRoi.GetRect(); // image roi rect 

						int minX = this->targetRoi.rightBottom.x - irr->width/2 ;
						int minY = this->targetRoi.rightBottom.y - irr->height/2 ; 

						if( false ) {
							int tMinX = irr->width/2;
							int tMinY = irr->height/2;

							minX = minX < tMinX ? tMinX : minX ;
							minY = minY < tMinY ? tMinY : minY ;
						}

						int maxX = this->targetRoi.leftTop.x + irr->width/2 ;
						int maxY = this->targetRoi.leftTop.y + irr->height/2 ;

						if( true ) {
							cv::Size * vSize = vi->GetVideoPlayerSize() ;  

							int tMaxX = vSize->width - irr->width/2; 
							int tMaxY = vSize->height - irr->height/2;

							maxX = maxX < tMaxX ? maxX : tMaxX ;
							maxY = maxY < tMaxY ? maxY : tMaxY ;  
						}

						cx = minX < cx ? cx : minX ;
						cy = minY < cy ? cy : minY ;

						cx = maxX < cx ? maxX : cx ;
						cy = maxY < cy ? maxY : cy ;
					}

					selRoi->SetCenter( cx, cy ); 

					repaint = 1 ; 

					// end when one roi selected and a point is not selected
				}
			}
		}

		// end of mouse drag of mouse up
	}
	
	if( MouseEvent::UP == event ) {  

		bool fixed = this->imageRoi.fixed && this->targetRoi.fixed; 

		if( ! fixed ) { 
			this->mousePressedX = -1 ;
			this->mousePressedY = -1 ;

			this->roiPreCenterX = -1 ;
			this->roiPreCenterY = -1 ;
		}

		cursor = System::Windows::Forms::Cursors::Default ;

		repaint = 1 ; 

	} else if( MouseEvent::CLICK == event ) { 
	} else if( MouseEvent::DBL_CLICK == event ) { 
		// when mouse double click, toggle the roi fixed property.
		
		bool fixed = ! this->targetRoi.fixed ;
		this->SetRoiFixed( fixed , vi );

		repaint = 1 ; 

		vi->showUiStatus();
	}

	if( nullptr != cursor ) {
		pbVideo->Cursor = cursor ; 
	}

	return repaint ; 

}

void VisionMatch::InitRoiData( bool locInit )
{
	this->imageRoi.InitData( locInit );
	this->targetRoi.InitData( locInit );

	this->RebuildTarget();
}

void VisionMatch::SetRoiFixed( bool fixed, VisionOptionInterface^ vi )
{
	Roi * roi ;

	roi = & this->targetRoi; 
	roi->fixed = fixed;

	roi = & this->imageRoi; 
	roi->fixed = fixed;

	if( fixed ) { 
		vi->InitChart(); 
	} else { 
	}
}

bool VisionMatch::IsTargetFixed()
{
	return this->targetRoi.fixed;
}
