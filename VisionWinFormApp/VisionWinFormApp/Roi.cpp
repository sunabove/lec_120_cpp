#include "StdAfx.h"
#include "Roi.h"


Roi::Roi(void)
{  
	this->InitData( true );
} 

Roi::~Roi(void)
{
} 

void Roi::InitData( bool locInit )
{ 
	if( locInit ) { 
		this->leftTop.x = 0;
		this->leftTop.y = 0;

		this->rightBottom.x = 0;
		this->rightBottom.y = 0; 
	}

	this->valid = false ; 

	this->selected = false ;

	this->mouseDragging = false ;  

	this->fixed = false ;

	this->simpleRect = false ; 
}


cv::Rect * Roi::GetRect()
{
	if( ! valid ) {

		const int x = leftTop.x < rightBottom.x ? leftTop.x : rightBottom.x ;
		const int y = leftTop.y < rightBottom.y ? leftTop.y : rightBottom.y ;

		int w = rightBottom.x - leftTop.x ;
		int h = rightBottom.y - leftTop.y ;

		w = w > 0 ? w : - w ;
		h = h > 0 ? h : - h ;

		rect.x = x;
		rect.y = y;
		rect.width = w;
		rect.height = h;

		leftTop.x = x;
		leftTop.y = y;

		rightBottom.x = x + w;
		rightBottom.y = y + h;

		center.x = x + w/2;
		center.y = y + h/2;

		valid = true ;
	}

	return & rect ; 
}

bool Roi::isValid()
{
	return valid ;
}

void Roi::InValidte()
{
	this->valid = false ; 
}

void Roi::UnSelected()
{
	this->selected = false ;

	this->leftTop.selected = false;
	this->rightBottom.selected = false ; 
}

bool Roi::IsSelected( int x, int y )
{
	cv::Rect * rect = this->GetRect();

	bool b = false ;

	const int m = 10 ;

	if( rect->x - m <= x && x <= rect->x + rect->width + m ) {
		if( rect->y - m <= y && y <= rect->y + rect->height + m ) {
			b = true; 
		}
	}

	this->selected = b;

	return this->selected;
}

ViPoint * Roi::GetCenter()
{
	this->GetRect();

	return & this->center;
}

void Roi::SetCenter( int cx, int cy )
{
	cv::Rect * rect = this->GetRect();

	int hw = rect->width / 2 ; 
	int hh = rect->height / 2 ;

	this->leftTop.x = cx - hw ;
	this->leftTop.y = cy - hh ;

	this->rightBottom.x = cx + hw ;
	this->rightBottom.y = cy + hh ;

	this->InValidte();
}

