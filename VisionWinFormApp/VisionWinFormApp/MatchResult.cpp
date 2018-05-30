#include "StdAfx.h"
#include "MatchResult.h"


MatchResult::MatchResult(void)
{
	this->minVal = -1 ;
	this->maxVal = -1 ;

	this->targetRoi = NULL ; 
}


MatchResult::~MatchResult(void)
{
}

void MatchResult::AdjustToRoi( long timeMiliSec, Roi * imageRoi, Roi * targetRoi , double scaleFactor )
{
	this->targetRoi = targetRoi;
	
	if( true ) { 
		ViPoint * leftTop = & imageRoi->leftTop ; 

		int dx = leftTop->x ;
		int dy = leftTop->y ;

		this->minLoc.x += dx ;
		this->minLoc.y += dy ; 

		this->maxLoc.x += dx ;
		this->maxLoc.y += dy ;

		this->toLoc.x += dx ;
		this->toLoc.y += dy ; 
	}

	cv::Point * targetCenter = this->targetRoi->GetCenter();

	double cx = ( maxLoc.x + toLoc.x )/2.0 ;
	double cy = ( maxLoc.y + toLoc.y )/2.0 ;   

	this->disp.SetDxPixel( cx - targetCenter->x ) ;
	this->disp.SetDyPixel( cy - targetCenter->y ); 

	this->disp.timeMiliSec = timeMiliSec;

	this->disp.SetScaleFactor( scaleFactor ) ; 

}

Disp * MatchResult::GetDisp()
{
	return & this->disp;
}
