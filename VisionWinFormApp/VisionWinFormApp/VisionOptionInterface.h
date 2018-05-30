#pragma once

#include "VisionInterface.h"
#include "Interval.h"
#include "VideoInfo.h"
#include "CannyOption.h" 
#include "MatchResult.h"

class Vision ;

interface class VisionOptionInterface
{

public: 

	int getMatchMethod() = 0 ;

	System::Windows::Forms::PictureBox^ getPbVideo() = 0 ;

	System::Windows::Forms::PictureBox^ getPbTarget() = 0 ; 

	bool isCoeffNorm() = 0 ;

	bool isAutoResize() = 0 ;

	cv::Size * GetVideoPlayerSize() = 0 ;

	void setVideoPlayerSize( int width, int height, bool autoResize )  = 0 ; 

	void SetFps( int fps ) = 0 ;

	int  GetFps() = 0 ;

	double  GetScaleFactor() = 0 ; 

	void showUiStatus() = 0 ;

	void showMsg( std::string * text ) = 0 ;

	void showMsg( const char * text ) = 0 ;

	void showMsg( System::String^ text ) = 0 ;

	void showException( System::Exception^ e ) = 0 ;

	void animateGetFrame(VideoInfo * videoInfo ) = 0 ;

	void animateImgPrcs(VideoInfo * videoInfo ) = 0 ; 

	void showMoviePlayInfo( VideoInfo * videoInfo  ) = 0 ;

	void showChartPaintOpt( int optLevel ) = 0 ; 

	bool SetTargetPbImage( Vision * vision, RECT * videoRect, Mat * img) = 0 ;

	void PaintVideo() = 0 ;

	bool isShowPrcsInfoOnImage() = 0 ; 

	bool isPreGaussianBlur() = 0 ;

	int  getPreGuassianBlurKSize() = 0;

	bool isPreHistEqualize()  = 0 ;

	bool isPreBinary() = 0 ;

	bool isPreAdaptiveThreshold() = 0 ;

	int getPreAdaptiveThresholdBSize() = 0 ;

	int  getPreBinaryThreshold() = 0 ; 

	CannyOption * getPreCannyOption()  = 0 ;

	bool showMatchMinValue() = 0 ;

	bool showMatchMaxValue() = 0 ;

	void ProcessMatchResult( MatchResult * matchResult, VideoInfo * videoInfo ) = 0 ;

	bool isFft() = 0 ;

	void InitChart() = 0 ;

	double GetHighPassFilterHz() = 0 ;

	double GetLowPassFilterHz() = 0 ;

};