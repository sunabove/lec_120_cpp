#pragma once
class ChartInfo
{
public:
	ChartInfo(void);
	~ChartInfo(void);

public:

	double minX ;
	double minY ;
	
	double maxX ; 
	double maxY ;

public:

	virtual double GetDy() ;
	virtual double GetYAxisInt() ; 

	virtual void SetCompVertData( double data ) ; 
	virtual void SetCompHoriData( double data ) ; 

	virtual void SetCompData( ChartInfo * chartInfo ) ; 

};

