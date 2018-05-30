#include "StdAfx.h"
#include "FontStyle.h"

#include "Vision.h"

FontStyle::FontStyle(void)
{
	this->fontFace = CV_FONT_HERSHEY_COMPLEX ;
	this->thickness = 1 ;
	this->fontScale = 1 ;
	this->lineType = 8 ; // CV_AA : anti aliasing
	this->backLight = true ;

	this->fillColor = Scalar( 255, 255 , 255)  ; // white
	this->textColor = Scalar( 0, 0 , 0) ; // black
}


FontStyle::~FontStyle(void)
{
}
