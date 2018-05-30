#include "StdAfx.h"
#include "VisionInterface.h"
#include "VisionSystem.h"

#include <ctime>
#include <windows.h> 
#include <shlobj.h>

int VisionSystem::camCount = 0;

VisionSystem::VisionSystem(void)
{
	this->camDevId = -1 ; // file 
	this->openFileName = "" ; // play file name 
	
	this->recordFileName = "c:/AAMyVideo.avi" ;
	this->videoWriter = NULL ; 

	this->playMode = PlayMode::CAM_DISABLED ; // cam_enabled, stopped
	this->recordMode = RecordMode::NO_RECORD ; // no recording
	this->uiMode = UiMode::MATCH  ; 

	this->rtrv = false; 

	this->isImgPrcs = false; 

	this->videoCapture = NULL ; 
	this->videoSrc = VideoSrc::DEVICE ;

	this->paintVideoUsingBitMap = true; 

	this->forwardFrameCnt = 0 ;
	this->backwardFrameCnt = 0 ;

	this->videoDrawing = false ; 
}


VisionSystem::~VisionSystem(void)
{	 
	release();
}

void VisionSystem::release() {
	if( NULL != videoCapture ) { 
		videoCapture->release();  

		this->videoCapture = NULL ; 
	}
	 
	frame.release(); 

	outImg.release(); 

	if( NULL != videoWriter ) {
		videoWriter->release() ;
		delete videoWriter ; 
		videoWriter = NULL ; 
	}
}

void VisionSystem::OnMouseEvent( MouseEvent event, int x, int y, VisionOptionInterface^ vi )
{
	RECT * rect = & this->videoRect ;

	if( rect->left <= x && x <= rect->right ) {
		if( rect->top <= y && y <= rect->bottom ) {

			int mx = x - rect->left ;
			int my = y - rect->top ;

			Vision * vision = & visionMatch ;

			int repaint = vision->OnMouseEvent( event, mx , my, vi );

			bool isPauseOrStop = ( PlayMode::PAUSE == this->playMode ) || ( PlayMode::STOP == this->playMode ); 
			if( isPauseOrStop && repaint ) {
				// paint video again in play mode is stop-mode or pause-mode after mouse event processing
				vi->PaintVideo();
			}
		}
	} else {
		int i = 0 ;
	}
}

bool VisionSystem::GetFrame(VisionOptionInterface^ vi )
{
	rtrv = false; 

	if( NULL == videoCapture ) {
		// Connect the cam device 
		if( this->openFileName.length() > 0 ) {
			// video file open
			this->videoSrc = VideoSrc::FILE  ; 
			videoCapture = new VideoCapture( openFileName );

			vi->showMsg( "cam open from file." ) ;

			int fps = (int) videoCapture->get( CV_CAP_PROP_FPS ) ; // frame rate
			if( fps > 0 ) {
				vi->SetFps( fps );
			} else {
				vi->showMsg( "¤Ð..¤Ð Video file fps is incorrect." ) ; 
			}
			
		} else if( this->camDevId >= 0 ) { 
			// video device open
			this->videoSrc = VideoSrc::DEVICE ;
			videoCapture = new VideoCapture(camDevId );
			vi->showMsg( "cam open from device [" + camDevId + "] .") ;
		} 

		this->paintVideoUsingBitMap = true; 

		int refFps = vi->GetFps();

		videoInfo.initData( videoCapture , refFps );

		psInterval.init(); 
	} 

	frame.release();

	if( VideoSrc::FILE == videoSrc ) { 
		// read from file
		if( forwardFrameCnt > 0 ) {
			// forward frame forward by 10 seconds
			while( videoInfo.GetFrameCnt() < forwardFrameCnt ) { 
				rtrv = videoCapture->read( frame );
				if( rtrv ) {   
					videoInfo.setCurrPos( videoCapture, vi->GetFps() );   
				} else {
					forwardFrameCnt = -1 ; 
					break ; 
				}
			}
			this->forwardFrameCnt = 0 ;
		} else if( backwardFrameCnt > 0 ) {
			if( NULL != this->videoCapture ) {
				this->videoCapture->release(); 
			}
			this->videoCapture = new VideoCapture( openFileName );

			this->paintVideoUsingBitMap = true; 

			int refFps = vi->GetFps();

			videoInfo.initData( videoCapture , refFps ); 

			while( videoInfo.GetFrameCnt() < backwardFrameCnt ) { 
				rtrv = videoCapture->read( frame );
				if( rtrv ) {   
					videoInfo.setCurrPos( videoCapture, vi->GetFps() );   
				} else {
					backwardFrameCnt = -1 ; 
					break ; 
				}
			}
			this->backwardFrameCnt = 0 ;
		} else {  
			// get one frame from video file
			rtrv = videoCapture->read( frame );
		} 
	} else { 
		// retrieve from device
		rtrv = videoCapture->retrieve( frame );
	} 

	if( rtrv ) {   
		videoInfo.setCurrPos( videoCapture, vi->GetFps() );  
		return true;
	} else {
		vi->showMsg( "Video Capture failed" );

		return false;
	}
}

bool VisionSystem::ProcessImageToRepaintVideo( VisionOptionInterface^ vi) {
	if( ! rtrv ) { 
		return false ;
	}  

	Vision * vision = & visionMatch ; 

	bool b = processImageImpl( vision, vi, & frame, & outImg, & videoInfo );  

	this->isImgPrcs = b ; 

	return b;
}

bool VisionSystem::ProcessImage( VisionOptionInterface^ vi)
{
	if( ! rtrv ) { 
		return false ;
	}  

	Vision * vision = & visionMatch ; 

	bool b = processImageImpl( vision, vi, & frame, & outImg, & videoInfo );  

	if( b ) {
		videoInfo.prcsFrameCnt ++ ;  
	}	

	this->isImgPrcs = b ; 

	videoInfo.imgWidth = frame.cols;
	videoInfo.imgHeight = frame.rows;
	videoInfo.psTimeMiliSec = this->psInterval.getDiffMiliSec();

	vi->showMoviePlayInfo( & videoInfo ) ; 

	if( VisionInterface::RecordMode::RECORD == this->recordMode ) {
		// video record 
		// save the original frame when the video source is device
		// save the out image when the video source is file
		Mat * recImg = VideoSrc::FILE == this->videoSrc ? & outImg : & frame ; 
		this->recordVideoFrame( recImg, vi );
	}

	bool showInfoOnImage = vi->isShowPrcsInfoOnImage() ;

	if( showInfoOnImage ) {  
		char * playInfoText = getMovePlayInfo( vision, vi, & outImg ); 
		this->showInfoOnImage( playInfoText, vision, & outImg ) ;
	}   

	return b ;
}

bool VisionSystem::PaintImage( VisionOptionInterface^ vi)
{
	if( this->videoDrawing ) {
		return false ; 
	}

	bool b = false ;

	this->videoDrawing = true ; 

	try { 
		Mat & img = outImg  ;  

		const int frameCnt = videoInfo.GetFrameCnt();

		if( 1 == frameCnt ) {
			bool autoResize = vi->isAutoResize();
		 
			int w = img.cols ;
			int h = img.rows ; 

			vi->setVideoPlayerSize( w, h, autoResize );  
		} 

		System::Windows::Forms::PictureBox^ pbVideo = vi->getPbVideo();

		bool painted = false;

		if( this->paintVideoUsingBitMap ) { 
			painted = Vision::SetPictureBoxImage( pbVideo, &videoRect, & outImg ); 
			if( false == painted ) {
				this->paintVideoUsingBitMap = false;
			}
		}

		if( false == painted ) {		
			Vision::DrawImageOnPictureBox( pbVideo, & videoRect, & outImg ); 
		} 

		b = painted;
	} catch ( System::Exception^ e ) {
		vi->showException( e );
	}

	this->videoDrawing = false ; 

	return b ;
}

bool VisionSystem::processImageImpl(Vision * vision, VisionOptionInterface^ vi, Mat * srcImg, Mat * outImg, VideoInfo * videoInfo )
{
	if( srcImg == NULL ) {
		return false ; 
	} 

	psInterval.setThen();

	bool b = vision->processImage( vi, srcImg, outImg, videoInfo );

	psInterval.setNow(); 

	return b;
}


bool VisionSystem::recordVideoFrame(Mat * frame , VisionOptionInterface^ vi)
{	
	if( NULL == videoWriter ) {
		Size size( frame->cols, frame->rows );

		cv::String * fileName = & this->recordFileName ; 
		int fourcc = CV_FOURCC('P','I','M','1') ; // MPEG-1 codec
		//fourcc = CV_FOURCC('D', 'I', 'V', '3') ; // DivX MPEG-4 codec
		//fourcc = CV_FOURCC('M', 'P', '4', '2') ; // MPEG-4 codec 
		int fps = vi->GetFps() ; 
		bool isColor = true ; 
		videoWriter = new VideoWriter( * fileName , fourcc , fps, size, isColor );

		// CV_FOURCC('D', 'I', 'V', '3') for DivX MPEG-4 codec 
		// CV_FOURCC('M', 'P', '4', '2') for MPEG-4 codec 
		// CV_FOURCC('D', 'I', 'V', 'X') for DivX codec  
		// CV_FOURCC('P','I','M','1') for MPEG-1 codec 
		// CV_FOURCC('I', '2', '6', '3') for ITU H.263 codec 
		// CV_FOURCC('M', 'P', 'E', 'G') for MPEG-1 codec 
	}

	videoWriter->write( * frame );

	return true;
}

char * VisionSystem::getMovePlayInfo( Vision * vision, VisionOptionInterface^ vi, Mat * img ) 
{	
	const int width = img->size().width ;
	const int height = img->size().height ; 

	const int x = width/20 ;
	const int y = height/10 ;

	const int m = 8 ;

	int frameCnt = videoInfo.GetFrameCnt();

	if( frameCnt > 0 )  {   
		int fps = videoInfo.fps;
		double diffSec = frameCnt /(fps + 0.0);

		String visionName = NULL == vision ? "Preview" : vision->toString();  

		long psDiffMiliSec = psInterval.getDiffMiliSec();

		bool shortForm = false ;
		if( shortForm ) {
			sprintf_s( playInfoText, "%dx%d %d (ms)", width, height, psDiffMiliSec );
		} else {
			sprintf_s( playInfoText, "[%s] [%dx%d] [%d (fps) * %.3f (s) = %06d (f)]  [%02d (ms)]", visionName.c_str(), width, height, fps, diffSec, frameCnt, psDiffMiliSec );
		}
	} else {
		sprintf_s( playInfoText, "Opening camera...." );
	}

	return playInfoText ; 
}

void VisionSystem::showInfoOnImage( const char * playInfo, Vision * vision, Mat * img )
{
	Scalar textColor = vision->GREEN ;  
	Scalar fillColor = vision->GRAY_144 ; 
	
	Point textOrg( 8, 8 ); 

	FontStyle fontStyle;
	fontStyle.fillColor = fillColor ;
	fontStyle.textColor = textColor ;
	fontStyle.fontScale = 0.5;
	fontStyle.hAlign = 0 ;
	fontStyle.vAlign = 2 ; 
	fontStyle.lineType = CV_AA ; 
	fontStyle.backLight = false ;

	vision->drawText( img, playInfo, & textOrg, & fontStyle );
}

int VisionSystem::getCameraCount(void) {
   // Get the count of camera available

   if( VisionSystem::camCount > 0 ) {
	   return VisionSystem::camCount;
   }

   cv::VideoCapture temp_camera;
   
   int camCount = 0 ;

   int maxTested = 10;
   for (int i = 0; i < maxTested; i++){
     cv::VideoCapture temp_camera(i); 
     bool res = temp_camera.isOpened() ;
     temp_camera.release();
     if (res) {
		 camCount ++;
     }
   }

   VisionSystem::camCount = camCount;

   return camCount ; 
}

void VisionSystem::setPlayMode(PlayMode playMode )
{
	const PlayMode prePlayMode = this->playMode ; 

	this->playMode = playMode ;

	if( PlayMode::STOP == playMode ) {
		// stop 

		visionMatch.initData();

		if( NULL != videoCapture && videoCapture->isOpened() ) {
			VideoCapture * oldVc = this->videoCapture ;
			this->videoCapture = NULL ; 
			oldVc->release(); 
		} 

		this->psInterval.init();

	} else if( playMode == PlayMode::PLAY ) {
		// play
		if( PlayMode::PAUSE == prePlayMode ) {
			// do nothing ....
		} else if( NULL != videoCapture && videoCapture->isOpened() ) {
			VideoCapture * oldVc = this->videoCapture ;
			this->videoCapture = NULL ; 
			oldVc->release(); 
		}
	} else if( playMode == PlayMode::PAUSE ) {
	}

}

void VisionSystem::setRecordMode(RecordMode recordMode, VisionOptionInterface^ vi)
{
	if( VisionInterface::RecordMode::RECORD == this->recordMode ) {
		// if current mode is no recording  
		this->recordMode = recordMode ;  

		if( NULL != videoWriter ) {
			videoWriter->release();
			//delete videoWriter ; 
			videoWriter = NULL ; 
		}
	} 

	if( VisionInterface::RecordMode::RECORD == recordMode ) {
		// if new mode is recording
		// set the record file name as current date time
		if( this->recordFileName.length() < 1 ) {  
			struct tm newtime;
			char am_pm[] = "AM";
			__time64_t long_time;
			char timebuf[26];
			errno_t err;

			// Get time as 64-bit integer.
			_time64( &long_time ); 
			// Convert to local time.
			err = _localtime64_s( &newtime, &long_time ); 
			if (err)
			{
				printf("Invalid argument to _localtime64_s.");
				exit(1);
			}
			if( newtime.tm_hour > 12 ){
				// Set up extension. 
				strcpy_s( am_pm, sizeof(am_pm), "PM" );
			}
			if( false && newtime.tm_hour > 12 ){
				// Convert from 24-hour 
				newtime.tm_hour -= 12;    // to 12-hour clock. 
			}
			if( newtime.tm_hour == 0 ){
				// Set hour to 12 if midnight.
				newtime.tm_hour = 12;
			}

			// Convert to an ASCII representation. 
			err = asctime_s(timebuf, 26, &newtime); 

			if( err ) {
				char buff[200] ;
				sprintf_s( buff, "C:/Vision_%d.mpg", GetTickCount() );
				this->recordFileName = buff  ; 
			} else {
				char buff[200] ;
				sprintf_s( buff, "C:/Vision_%s.mpg", timebuf );
				this->recordFileName = buff  ; 
			}  
		}

		// end of setting the record file name as current date time  

		this->recordMode = recordMode ;
	} else if( VisionInterface::RecordMode::NO_RECORD == recordMode ) {
		// if new mode is no recording 
		this->recordFileName = "" ; 

		this->recordMode = recordMode ;
	}

	// change record mode 
	this->recordMode = recordMode ;  

	if( recordFileName.length() > 0 ) { 
		std::string msg = "Recording file name: " + this->recordFileName ; 
		vi->showMsg( msg.c_str() );
	} else {
		vi->showMsg( "No recording." );
	}
}

int VisionSystem::getFrameCnt()
{
	return this->videoInfo.GetFrameCnt();
}

void VisionSystem::PlayForward(VisionOptionInterface^ vi)
{
	int totFrameCnt = this->videoInfo.totFrameCnt ; 
	int fps = vi->GetFps();

	int forwardFrameCnt = videoInfo.GetFrameCnt() + 10*fps ; // 10 second frame count

	forwardFrameCnt = forwardFrameCnt > totFrameCnt ? totFrameCnt : forwardFrameCnt ;

	this->forwardFrameCnt = forwardFrameCnt ; 
}

void VisionSystem::PlayBackward(VisionOptionInterface^ vi)
{	 
	int fps = vi->GetFps();

	int backwardFrameCnt = videoInfo.GetFrameCnt() - 10*fps ; // 10 second frame count

	backwardFrameCnt = backwardFrameCnt < 1 ? 1 : backwardFrameCnt ;

	this->backwardFrameCnt = backwardFrameCnt ; 
}

void VisionSystem::PlayAtPosPct( double posPct )
{
	// play video at specific position in unit percentage

	int totFrameCnt = this->videoInfo.totFrameCnt ;  

	int currFrameCnt = videoInfo.GetFrameCnt();

	int frameCnt = (int) ( totFrameCnt*posPct + 0.5 ) ; // 10 second frame count

	if( frameCnt < currFrameCnt ) {
		this->backwardFrameCnt = frameCnt ; 
	} else if( frameCnt > currFrameCnt ) {
		this->forwardFrameCnt = frameCnt ; 
	} 
}

