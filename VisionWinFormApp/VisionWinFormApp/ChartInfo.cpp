#include "StdAfx.h"
#include "ChartInfo.h"


ChartInfo::ChartInfo(void)
{
	this->minX = 0 ;
	this->minY = 0 ;

	this->maxX = 0;
	this->maxY = 0 ; 
}


ChartInfo::~ChartInfo(void)
{
}

double ChartInfo::GetDy()
{
	return this->maxY - this->minY ; 
}

void ChartInfo::SetCompVertData( double data )
{
	if( data > maxY ) {
		maxY = data ; 
	}

	if( data < minY ) {
		minY = data ; 
	}
}

void ChartInfo::SetCompHoriData( double data )
{
	if( data > maxX ) {
		maxX = data ; 
	}

	if( data < minX ) {
		minX = data ; 
	}
}

void ChartInfo::SetCompData( ChartInfo * chartInfo )
{
	this->SetCompHoriData( chartInfo->minX );
	this->SetCompHoriData( chartInfo->maxX );

	this->SetCompVertData( chartInfo->minY );
	this->SetCompVertData( chartInfo->maxY );
}

double ChartInfo::GetYAxisInt()
{
	double dy = this->GetDy();

	int i = (int)( dy/10 ) ;

	if( i < 1 ) {
		i = 1;
	} else if( i < 10 ) {
		i = 10 ;
	} else {
		int t = (i/10)*10;		

		t = t < i ? t + 10 : t ;

		i = t; 
	}



	return i ;
}


