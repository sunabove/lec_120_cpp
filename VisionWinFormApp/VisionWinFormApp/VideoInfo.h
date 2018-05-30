#pragma once

#include <opencv2\opencv.hpp> 

#include "ComObject.h"
#include "Interval.h" 

using namespace cv;

class VideoInfo : ComObject
{

public:
	VideoInfo(void);
	~VideoInfo(void);

private:
	int			frameCnt ;      // frame position : 0 - based index 

public: 

	int			imgWidth ;		// image height
	int			imgHeight ;     // image width
	int			psTimeMiliSec ; // processing time

	char		totPlayTimeText[ 10 ]; // total playing time text

	int			totFrameCnt;    // total frame count   
	int			prcsFrameCnt ;  // processing frame count
	int			fps ;           // frames per second

public:
	void initData( VideoCapture * videoCapture, int refFps ) ;
	void setCurrPos( VideoCapture * videoCapture , int refFps  ) ;

	bool isEndPos() ;
	bool isStartPos() ;

	int  GetFrameCnt();

};

