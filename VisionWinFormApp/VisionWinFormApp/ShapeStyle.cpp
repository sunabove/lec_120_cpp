#include "StdAfx.h"
#include "ShapeStyle.h"

#include "Vision.h"

ShapeStyle::ShapeStyle(void)
{
	fillColor = Scalar( 255, 255 , 255) ; // white
	lineColor = Scalar( 0, 0 , 0) ; // black 

	thickness = 1;
	lineType = 8;

	showTick = false ;
	tickWidth = 6;
	tickHeight = 6; 

	tipLength = 0 ;

	drawCenterCross = false ; 
} 


ShapeStyle::~ShapeStyle(void)
{
}
