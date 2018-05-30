#include "StdAfx.h"
#include "VideoInfo.h"


VideoInfo::VideoInfo(void)
{
	totFrameCnt = 0;  

	frameCnt = 0; 

	prcsFrameCnt = 0 ;

	imgWidth = 0 ;
	imgHeight = 0 ;
	psTimeMiliSec = 0 ; 
}


VideoInfo::~VideoInfo(void)
{
}

void VideoInfo::initData( VideoCapture * videoCapture, int refFps ) {

	int totPlayTime_ms = 0 ; 

	this->fps = refFps ; 

	if( NULL != videoCapture ) { 
		totFrameCnt = (int) videoCapture->get( CV_CAP_PROP_FRAME_COUNT  ); // total frame count  

		if( 0 == fps ) {
			totPlayTime_ms = 0 ; 
		} else { 
			totPlayTime_ms = (int) ( (totFrameCnt/(fps+0.0))*1000 ) ; // total play time in mili seconds	
		}
	} else {
		totPlayTime_ms = 0 ;
	}

	ComObject::formatHMS( totPlayTimeText, 10, (int) totPlayTime_ms );

	frameCnt = 0; 

	prcsFrameCnt = 0 ;

	imgWidth = 0 ;
	imgHeight = 0 ;
	psTimeMiliSec = 0 ;
}

void VideoInfo::setCurrPos( VideoCapture * videoCapture, int refFps )
{
	frameCnt ++ ; 
	this->fps = refFps ; 
}

bool VideoInfo::isEndPos() {
	return totFrameCnt == ( frameCnt + 1 );
}

bool VideoInfo::isStartPos() {
	return 0 == frameCnt ;
}

int VideoInfo::GetFrameCnt()
{
	return this->frameCnt;
}
