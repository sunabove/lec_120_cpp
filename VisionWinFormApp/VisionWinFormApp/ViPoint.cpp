#include "StdAfx.h"
#include "ViPoint.h"


ViPoint::ViPoint(void)
{
	this->selected = false ;
}


ViPoint::~ViPoint(void)
{
}

int ViPoint::Distum( int x, int y )
{
	int dx = this->x - x;
	int dy = this->y - y;

	return dx*dx + dy*dy ;
}

int ViPoint::Distum( cv::Point * p )
{
	return Distum( p->x, p->y );
}

bool ViPoint::IsSelected( int x, int y , int minDistum )
{
	int distum = this->Distum( x, y );

	this->selected = ( distum <= minDistum ) ;

	return this->selected ;

}
