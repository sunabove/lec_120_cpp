#pragma once
#include "vision.h"

#include "MatchResult.h"

#include "Roi.h"

class VisionMatch :
	public Vision
{
public:
	VisionMatch(void);
	~VisionMatch(void);

public: 
	
	Roi imageRoi ;  
	Roi targetRoi ; 

	int mousePressedX ;
	int mousePressedY ; 

	int roiPreCenterX;
	int roiPreCenterY;

	Mat * target ; 
	Mat * coeff ;

	Mat targetColorImg ; 

	bool buildTarget ;

	int  targetBuildCnt ;   

	virtual void initData();
	virtual void release();
	
	virtual bool preProcessImage(VisionOptionInterface^ vi, Mat * grayImage );

	virtual bool processImage(VisionOptionInterface^ vi,  Mat * srcImg, Mat * outImg, VideoInfo * videoInfo );

	virtual bool postProcessImage(VisionOptionInterface^ vi,  Mat * srcImg, Mat * outImg );

	virtual void showMsgOnImage( cv::String * msg, Scalar * textColor, double fontScale, Mat * img );

	virtual void drawRoiAndTarget( Mat * img, Roi * imageRoi, Roi * targetRoi );

	virtual void drawMatchInfoOnImage( Mat * img, MatchResult * matchResult, VisionOptionInterface^ vi );

	virtual String toString();
	
	virtual void setTarget( Mat * target );
	
	virtual void RebuildTarget() ;

	virtual void InitRoiData( bool locInit );

	virtual bool IsTargetFixed() ; 

	virtual void SetRoiFixed( bool fixed, VisionOptionInterface^ vi );

	virtual int OnMouseEvent( MouseEvent event, int x, int y, VisionOptionInterface^ vi ) ;

};

