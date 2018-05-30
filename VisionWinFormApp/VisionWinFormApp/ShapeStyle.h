#pragma once
#include "style.h"
class ShapeStyle :
	public Style
{
public:
	ShapeStyle(void);
	~ShapeStyle(void);

public:

	cv::Scalar lineColor ;
	cv::Scalar fillColor ;

	int thickness ;
	int lineType ;

	int tickWidth ;
	int tickHeight ;

	double tipLength ; 

	bool showTick ; 
	bool drawCenterCross ; 
};

