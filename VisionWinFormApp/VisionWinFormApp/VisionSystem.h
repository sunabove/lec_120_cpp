#pragma once

#include <opencv2\opencv.hpp>
#include "ComObject.h"

#include "CvImage.h"
#include "Interval.h" 
#include "VisionMatch.h"
#include "VideoInfo.h"

using namespace cv;

class VisionSystem : ComObject , VisionInterface
{
public:
	VisionSystem(void);
	~VisionSystem(void);

	static int camCount;

	int camDevId ; 
	String openFileName ; 
	VideoSrc videoSrc ; // videoSource : 0 : device : 1 : file
	VideoInfo videoInfo ; 

	String recordFileName ; 
	VideoWriter * videoWriter ; 

	VideoCapture * videoCapture;

	PlayMode playMode ;
	RecordMode recordMode ;
	UiMode uiMode; 
	
	bool rtrv; // retrieve
	bool isImgPrcs ; // is image processing

	Mat frame ;
	Mat outImg ; 

	int forwardFrameCnt ; 
	int backwardFrameCnt ; 

	bool paintVideoUsingBitMap ; 

	Interval psInterval ;

	CvImage cvImagePbVideo ;

	VisionMatch visionMatch; 

	char playInfoText[ 300 ] ;

	RECT videoRect; 

	bool videoDrawing ; 

public:

	virtual void release();

	virtual char * getMovePlayInfo( Vision * vision, VisionOptionInterface^ vi, Mat * img ) ;

	virtual void showInfoOnImage( const char * playInfo, Vision * vision, Mat * img ) ;

	virtual bool GetFrame( VisionOptionInterface^ vi ) ;

	virtual bool ProcessImageToRepaintVideo( VisionOptionInterface^ vi ) ;

	virtual bool ProcessImage( VisionOptionInterface^ vi ) ;

	virtual bool processImageImpl( Vision * vision, VisionOptionInterface^ vi, Mat * srcImg, Mat * outImg, VideoInfo * videoInfo ) ; 

	virtual bool PaintImage( VisionOptionInterface^ vi );

	virtual bool recordVideoFrame( Mat * frame , VisionOptionInterface^ vi ) ;

	virtual void OnMouseEvent( MouseEvent event, int x, int y, VisionOptionInterface^ vi ) ; 

	virtual void setPlayMode( PlayMode playMode ) ; 

	virtual void setRecordMode( RecordMode recordMode, VisionOptionInterface^ vi ) ;

	virtual int  getFrameCnt( ) ;

	virtual void PlayForward(VisionOptionInterface^ vi) ;

	virtual void PlayBackward(VisionOptionInterface^ vi) ; 

	virtual void PlayAtPosPct( double posPct ) ; 

	static int getCameraCount(void);


};

