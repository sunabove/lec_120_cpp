#include "StdAfx.h"
#include "Interval.h"


Interval::Interval(void)
{
	then = 0;
	now = 0; 
	diffMiliSum = 0;
}


Interval::~Interval(void)
{
}

void Interval::init()
{ 

	then = GetTickCount();
	now = then ;
	diffMiliSum = 0 ;
	
}

void Interval::setThen() {
	then = GetTickCount();
}

void Interval::setNow() {
	now = GetTickCount(); 

	diffMiliSum += getDiffMiliSec() ;
}


double Interval::getDiffSec() {
	double diffSec = (now - then)/(1000.0) ;
	return diffSec;
}

DWORD Interval::getDiffMiliSec()
{
	return now - then;
}



