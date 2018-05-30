#pragma once
class Disp
{

public:
	Disp(void);
	~Disp(void);

private:
	double dxPixel;
	double dyPixel; 
	double scaleFactor ;

public:
	long timeMiliSec ;  
	
private:
	virtual double convertPixelToMeter( double pixel, int dpi ) ;

public:
	virtual void SetScaleFactor( double scaleFactor ) ;

	virtual double GetDxMeter( );
	virtual double GetDyMeter( );

	virtual void SetDxPixel( double dxPixel ) ;
	virtual void SetDyPixel( double dyPixel ) ;

	virtual double GetDxPixel() ;
	virtual double GetDyPixel() ; 
	
};

