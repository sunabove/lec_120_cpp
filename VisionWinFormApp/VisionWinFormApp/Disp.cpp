#include "StdAfx.h"
#include "Disp.h"


Disp::Disp(void)
{
	timeMiliSec = 0 ; 
	dxPixel = 0 ;
	dyPixel = 0 ;
	scaleFactor = 1.0 ;
}

Disp::~Disp(void)
{
}

double Disp::GetDxMeter( )
{
	return dxPixel*scaleFactor ;
}

double Disp::GetDyMeter( )
{
	return dyPixel*scaleFactor ;
}

void Disp::SetDxPixel( double dxPixel )
{
	this->dxPixel = dxPixel;
}

void Disp::SetDyPixel( double dyPixel )
{
	this->dyPixel = dyPixel;
}

double Disp::GetDxPixel()
{
	return dxPixel ;
}

double Disp::GetDyPixel()
{
	return dyPixel ;
}

double Disp::convertPixelToMeter( double pixel , int dpi )
{
	return pixel*0.0254/(dpi + 0.0); 
}

void Disp::SetScaleFactor( double scaleFactor )
{
	this->scaleFactor = scaleFactor ;
}


