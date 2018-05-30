#include "StdAfx.h"
#include "Vision.h"
#include "CvImage.h"

Vision::Vision(void) 
	: RED( 0, 0 , 255), BLUE( 255, 0 , 0) , GREEN( 0, 255 , 0) , YELLOW( 0, 255 , 255 )
	, WHITE( 255, 255 , 255), BLACK( 0, 0 , 0) , CYAN( 255, 255 , 0 ), VIOLET( 255, 0 , 255)
	, GRAY_144( 144, 144 , 144) , GRAY_200( 200, 200 , 200) , GRAY_210( 210, 210 , 210), GRAY_220( 220, 220 , 220)
	, HEX_BROWN_A52A2A( 0x2A, 0x2A, 0xA5 ) , HEX_CRIMSON_DC143C( 0x3C, 0x14, 0xDC ) , HEX_HOTPINK_FF69B4( 0xB4, 0x69, 0xFF )
{ 
}

Vision::~Vision(void)
{
}

void Vision::drawCircle(Mat * img, cv::Point * center , int radius, Scalar * fillColor, Scalar * lineColor )
{
	int thickness = 1 ; 
	const Scalar * color ;
	int linetype = 8 ; 

	if( NULL != fillColor ) { 
		thickness = -1;
		color = fillColor  ;  
		cv::circle( *img, * center, radius, * color, thickness, linetype ); 
	}

	if( NULL != lineColor ) {
		if( NULL != fillColor ) { 
			thickness = 3;
			color = & WHITE ; 

			cv::circle( *img, * center, radius, * color, thickness, linetype );
		}

		thickness = 2 ;
		color = lineColor ; 
		cv::circle( *img, * center, radius, * color, thickness, linetype );
	}
	
}

void Vision::drawText(Mat * img, const char * text, cv::Point * point, FontStyle * fontStyle )
{
	Scalar * textColor = & fontStyle->textColor ;
	Scalar * fillColor = & fontStyle->fillColor ;
	double fontScale = fontStyle->fontScale ;
	int hAlign = fontStyle->hAlign ;
	int vAlign = fontStyle->vAlign ;
	int fontFace = fontStyle->fontFace ; // FONT_HERSHEY_PLAIN;;
	
	int thickness = fontStyle->thickness ; 
	int linetype = fontStyle->lineType;

	//cv::Size textSize = cv::getTextSize( text, fontFace, fontScale, thickness, 0);

	cv::Size textSize = getTextSize( text, fontStyle );

	int tx = point->x ;
	int ty = point->y ;

	if( 1 == hAlign ) {
		tx -= textSize.width/2;
	} else if( 2 == hAlign ) {
		tx -= textSize.width ; 
	}

	if( 1 == vAlign ) {
		ty += textSize.height/2;
	} else if( 2 == vAlign ) {
		ty += textSize.height;
	}

	if( NULL != fillColor ) { 

		int m = textSize.height/4;

		int x = tx - m;
		int y = ty - textSize.height - m;

		int w = textSize.width + 2*m ;
		int h = textSize.height + 3*m ;

		cv::Point from( x, y );
		cv::Point to( x + w, y + h );

		cv::rectangle( * img, from, to, * fillColor, -1); 
	}

	Point textOrg( tx, ty ); 

	Scalar * color ;
	bool backLight = fontStyle->backLight ; 

	// 8 (or omitted) - 8-connected line.
    // 4 - 4-connected line.
	// CV_AA - anti aliased line.


	if( backLight ) { 
		color = &WHITE  ;
		thickness = 2;  
		linetype = fontStyle->lineType ; 

		putText( *img, text, textOrg, fontFace, fontScale, * color, thickness, linetype );
	}

	color = textColor ;
	thickness = fontStyle->thickness ;
	linetype = fontStyle->lineType ; 
	putText( *img, text, textOrg, fontFace, fontScale, * color, thickness, linetype );

}

bool Vision::doGrayScale(Mat * srcImg, Mat * outImg, VisionOptionInterface^ vi )
{
	cvtColor( * srcImg, * outImg , CV_BGR2GRAY ); 

	return true;
}

bool Vision::doInvert(Mat * srcImg, Mat * outImg, VisionOptionInterface^ vi)
{
	if( false ) {  
		Scalar s( 255, 255, 255 );
		Mat subMat = Mat::ones( srcImg->size(), srcImg->type())*255 ;
		cv::subtract( subMat, * srcImg, * outImg );
	}

	return true;
}

void Vision::drawDecoRect( Mat * img, cv::Rect * rect , ShapeStyle * shapeStyle )
{
	Scalar * color;
	const int thickness = shapeStyle->thickness ;
	int linetype = shapeStyle->lineType ;

	const int x = rect->x ;
	const int y = rect->y ;

	const int w = rect->width;
	const int h = rect->height ;

	int m;

	if( true ) {
		color = & shapeStyle->fillColor ; 
		m = 2;
		cv::Rect tRect( x - m, y - m , w + 2*m, h + 2*m );	
		cv::rectangle( * img, tRect, * color, thickness, linetype );
	}

	if( true ) {
		color = & shapeStyle->lineColor ; 
		m = 1;
		cv::Rect tRect( x - m, y - m , w + 2*m, h + 2*m );	
		cv::rectangle( * img, tRect, * color, thickness, linetype );
	}

	if( true ) {
		color = & shapeStyle->lineColor ; 
		m = 0;
		cv::Rect tRect( x - m, y - m , w + 2*m, h + 2*m );	
		cv::rectangle( * img, tRect, * color, thickness, linetype );
	}

	if( true ) {  
		color = & shapeStyle->fillColor ; 
		m = -1 ;
		cv::Rect tRect( x - m, y - m , w + 2*m, h + 2*m );	
		cv::rectangle( * img, tRect, * color, thickness, linetype );
	} 

	// draw the ticks 
	bool showTick = shapeStyle->showTick ;

	if( showTick ) {   
		m = 1;
		int x = rect->x - m;
		int y = rect->y - m ;
		int w = shapeStyle->tickWidth ;
		int h = shapeStyle->tickHeight ;

		Rect tick( x, y, w, h ); 
		shapeStyle->thickness = -1;
		shapeStyle->lineColor = WHITE ;  
		this->drawTickRect( img, & tick, shapeStyle );
		shapeStyle->thickness = 1;
		shapeStyle->lineColor = BLACK ;  
		this->drawTickRect( img, & tick, shapeStyle );
	}

	if( showTick ) {  
		m = 1; 
		int x = rect->x + rect->width - shapeStyle->tickWidth + m ;
		int y = rect->y + rect->height - shapeStyle->tickHeight + m ;
		int w = shapeStyle->tickWidth ;
		int h = shapeStyle->tickHeight ;

		Rect tick( x, y, w, h ); 
		shapeStyle->thickness = -1; 
		shapeStyle->lineColor = WHITE ; 
		this->drawTickRect( img, & tick, shapeStyle );
		shapeStyle->thickness = 1; 
		shapeStyle->lineColor = BLACK ; 
		this->drawTickRect( img, & tick, shapeStyle );
	}
	// end of drawing the ticks

	// draw center cross
	if( shapeStyle->drawCenterCross ) {
		cv::Point center( x + w/2, y + h/2 );
		shapeStyle->fillColor = YELLOW ; 
		shapeStyle->lineColor = RED ; 
		shapeStyle->thickness = 2 ;
		shapeStyle->lineType = 8 ;
		this->drawCross( img, & center, 6, shapeStyle );
	}
}

void Vision::drawSimpleRect( Mat * img, cv::Rect * rect , ShapeStyle * shapeStyle )
{
	Scalar * color;
	const int thickness = shapeStyle->thickness ;
	int linetype = shapeStyle->lineType ;

	int x = rect->x ;
	int y = rect->y ;

	int w = rect->width;
	int h = rect->height ; 
	
	if( true ) {
		color = & shapeStyle->fillColor ;  
		int m = thickness ; 
		cv::Rect tRect( x - m, y - m , w + 2*m, h + 2*m );	
		cv::rectangle( * img, tRect, * color, thickness/2, linetype );
	} 

	if( true ) {
		color = & shapeStyle->lineColor ;  
		int m = 0 ; 
		cv::Rect tRect( x - m, y - m , w + 2*m, h + 2*m );	
		cv::rectangle( * img, tRect, * color, thickness, linetype );
	} 
}

void Vision::drawTickRect( Mat * img, cv::Rect * rect , ShapeStyle * shapeStyle )
{
	Scalar * color;
	const int thickness = shapeStyle->thickness ;
	int linetype = shapeStyle->lineType ;

	int x = rect->x ;
	int y = rect->y ;

	int w = rect->width;
	int h = rect->height ;

	int m ;

	if( true ) {
		color = & shapeStyle->fillColor ; 
		m = 1;
		cv::Rect tRect( x - m, y - m , w + 2*m, h + 2*m );	
		cv::rectangle( * img, tRect, * color, thickness, linetype );
	}

	if( true ) {
		color = & shapeStyle->lineColor ; 
		m = 0;
		cv::Rect tRect( x - m, y - m , w + 2*m, h + 2*m );	
		cv::rectangle( * img, tRect, * color, thickness, linetype );
	}

	if( true ) {
		color = & shapeStyle->fillColor ; 
		m = -1;
		cv::Rect tRect( x - m, y - m , w + 2*m, h + 2*m );	
		cv::rectangle( * img, tRect, * color, thickness, linetype );
	} 
}

void Vision::drawCross( Mat * img, cv::Point * center, int crossSize, ShapeStyle * shapeStyle )
{
	const int cx = center->x ;
	const int cy = center->y ; 

	// drawing background
	if( true ) { 
		int x0 = cx - crossSize/2;
		int x1 = cx + crossSize/2; 
		const int y = cy ; 
		const int th = shapeStyle->thickness; 
		int m = th ; 

		cv::Point p( x0 - m , y - m );
		cv::Point q( x1 + m , y + m );  
		cv::rectangle( * img, p, q, shapeStyle->fillColor , -1, shapeStyle->lineType );
	}

	if( true ) { 
		int y0 = cy - crossSize/2;
		int y1 = cy + crossSize/2;
		const int x = cx; 
		const int th = shapeStyle->thickness; 
		int m = th ; 

		cv::Point p( x - m , y0 - m );
		cv::Point q( x + m , y1 + m );  
		cv::rectangle( * img, p, q,  shapeStyle->fillColor, -1, shapeStyle->lineType );
	}
	// end of drawing background 

	// draw foreground
	if( true ) { 
		int x0 = cx - crossSize/2;
		int x1 = cx + crossSize/2; 
		const int y = cy ; 
		int th = shapeStyle->thickness; 
		int m = th/2 ; 

		cv::Point p( x0 - m , y - m );
		cv::Point q( x1 + m , y + m );   
		cv::rectangle( * img, p, q, shapeStyle->lineColor, -1, shapeStyle->lineType );
	}

	if( true ) { 
		int y0 = cy - crossSize/2;
		int y1 = cy + crossSize/2;
		const int x = cx; 
		int th = shapeStyle->thickness; 
		int m = th/2 ; 

		cv::Point p( x - m , y0 - m );
		cv::Point q( x + m , y1 + m );  
		cv::rectangle( * img, p, q, shapeStyle->lineColor, -1, shapeStyle->lineType );
	}
	// end of drawing foreground
}

void Vision::drawLine( Mat * img, cv::Point * p, cv::Point * q , ShapeStyle * shapeStyle )
{
	int thickness = (shapeStyle->thickness*3/2);
	thickness = thickness < 3 ? 3 : thickness ;

	if( shapeStyle->tipLength == 0 ) { 
		cv::line( * img, * p, * q, shapeStyle->fillColor, thickness, shapeStyle->lineType );
		cv::line( * img, * p, * q, shapeStyle->lineColor,  shapeStyle->thickness , shapeStyle->lineType );
	} else {
		cv::arrowedLine( * img, * p, * q, shapeStyle->fillColor, thickness, shapeStyle->lineType, 0, shapeStyle->tipLength );
		cv::arrowedLine( * img, * p, * q, shapeStyle->lineColor,  shapeStyle->thickness , shapeStyle->lineType, 0, shapeStyle->tipLength );
	}
}

cv::Size Vision::getTextSize( const char * text, FontStyle * fontStyle )
{
	return cv::getTextSize( text, fontStyle->fontFace, fontStyle->fontScale, fontStyle->thickness, 0 );
}

bool Vision::SetPictureBoxImage( System::Windows::Forms::PictureBox^ pb, RECT * videoRect, Mat * img )
{
	// some bug occurred when playing some video file
	// don't use this function as possible as.
	
	const int imgWidth = img->cols;
	const int imgHeight = img->rows;

	const int imgStep = (int) img->step.buf[0]; 
	const int imgType = img->type();
	const int channel = img->channels();
	const int depth = img->depth();  

	if( true ) {
		videoRect->left = ( pb->Size.Width - imgWidth )/2;
		videoRect->top = ( pb->Size.Height - imgHeight )/2;
		videoRect->right = videoRect->left + imgWidth;
		videoRect->bottom = videoRect->right + imgHeight ;
	}

	System::Drawing::Imaging::PixelFormat format = System::Drawing::Imaging::PixelFormat::Format24bppRgb; 

	if( imgWidth == imgStep ) {
		format = System::Drawing::Imaging::PixelFormat::Format8bppIndexed;  
	}

	System::IntPtr imgPtr( img->data ); 

	bool b = false ; 
	try {   
		System::Drawing::Bitmap^ bitMap  = gcnew System::Drawing::Bitmap( imgWidth, imgHeight, imgStep, format, imgPtr );
		pb->Image = bitMap ; 

		b = true ; 
	} catch(System::Exception^ ex ) { 

		b = false ; 
		System::Console::WriteLine( L"Error in Vision::SetPictureBoxImage(...)" );

		System::Console::WriteLine( ex );

		if( ex->InnerException ) {
			System::Console::WriteLine( "Inner Exception: {0}", ex->InnerException );
		} 
	} 

	return b ; 
}

bool Vision::DrawImageOnPictureBox( System::Windows::Forms::PictureBox^ pb, RECT * videoRect, Mat * img ) {

	bool b = false ; 

	System::Drawing::Size^ size = pb->Size;

	int imgWidth = img->cols ; 
	int imgHeight = img->rows ; 

	int x = (int)( (size->Width - imgWidth)/2.0 - 1 );
	int y = (int)( (size->Height - imgHeight)/2.0 - 1 );

	videoRect->left = x;
	videoRect->top = y;
	videoRect->right = x + imgWidth;
	videoRect->bottom = y + imgHeight ;

	HWND hwnd = static_cast<HWND>( pb->Handle.ToPointer()); 

	HDC hdc = GetDC( hwnd );

	CvImage cvImagePbVideo ;

	IplImage * image = & IplImage( * img );

	cvImagePbVideo.CopyOf( image ); 

	cvImagePbVideo.DrawToHDC( hdc, videoRect ); 

	ReleaseDC( hwnd, hdc );

	b = true ; 

	return b ;

}

