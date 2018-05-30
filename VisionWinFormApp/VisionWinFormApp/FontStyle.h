#pragma once
#include "style.h"

class FontStyle :
	public Style 
{
public:
	FontStyle(void);
	~FontStyle(void);

public:

	int fontFace ;
	double fontScale;

	int thickness ;
	int lineType ;

	int hAlign ;
	int vAlign ;

	cv::Scalar textColor ; 
	cv::Scalar fillColor ;
	bool backLight ;  

public:

};

