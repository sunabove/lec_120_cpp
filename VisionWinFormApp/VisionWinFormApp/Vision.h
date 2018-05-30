#pragma once

#include <opencv2\opencv.hpp> 

#include "ComObject.h"
#include "VisionOptionInterface.h"

#include "ShapeStyle.h"
#include "FontStyle.h"

using namespace cv;

public class Vision : ComObject, public VisionInterface
{
public:
	Scalar RED ;
	Scalar BLUE ;
	Scalar GREEN ;
	Scalar YELLOW ;
	Scalar WHITE ;
	Scalar BLACK ;
	
	Scalar CYAN ;
	Scalar VIOLET ;
	Scalar GRAY_144 ; 
	Scalar GRAY_200 ;
	Scalar GRAY_210 ;
	Scalar GRAY_220 ;

	Scalar HEX_BROWN_A52A2A;
	Scalar HEX_CRIMSON_DC143C;
	Scalar HEX_HOTPINK_FF69B4 ; 

public:
	Vision(void);
	~Vision(void);

public: 

	cv::String msg ; // message 

public: 

	virtual bool doGrayScale( Mat * srcImg, Mat * outImg, VisionOptionInterface^ vi ) ;

	virtual bool doInvert( Mat * srcImg, Mat * outImg, VisionOptionInterface^ vi ) ;

	virtual bool processImage( VisionOptionInterface^ vi, Mat * srcImg, Mat * outImg , VideoInfo * videoInfo ) = 0 ; 

	virtual String toString() = 0;

	virtual cv::Size getTextSize( const char * , FontStyle * fontStyle ) ; 

	virtual void drawCircle( Mat * img, cv::Point * center , int radius, Scalar * fillColor, Scalar * lineColor );

	virtual void drawDecoRect( Mat * img, cv::Rect * rect , ShapeStyle * shapeStyle );

	virtual void drawSimpleRect( Mat * img, cv::Rect * rect , ShapeStyle * shapeStyle );

	virtual void drawTickRect( Mat * img, cv::Rect * rect , ShapeStyle * shapeStyle );

	virtual void drawLine( Mat * img, cv::Point * p, cv::Point * q , ShapeStyle * shapeStyle );

	virtual void drawCross( Mat * img, cv::Point * center, int crossSize, ShapeStyle * shapeStyle );

	virtual void drawText( Mat * imag, const char * text, cv::Point * point, FontStyle * fontStyle );

	virtual int OnMouseEvent( MouseEvent event, int x, int y, VisionOptionInterface^ vi ) = 0 ; 

	static bool SetPictureBoxImage( System::Windows::Forms::PictureBox^ pb, RECT * videoRect, Mat * img );

	static bool DrawImageOnPictureBox( System::Windows::Forms::PictureBox^ pb, RECT * videoRect, Mat * img );

};

