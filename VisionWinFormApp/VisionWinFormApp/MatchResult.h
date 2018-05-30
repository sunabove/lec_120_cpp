#pragma once

#include "comobject.h"

#include "Roi.h"
#include "Disp.h"

class MatchResult :
	public ComObject
{
public:
	MatchResult(void);
	~MatchResult(void);

private:

	Roi * targetRoi ;
	Disp disp;

public:
	
	cv::Point * matchLoc ;
	cv::Point toLoc ;

	cv::Point minLoc ;
	cv::Point maxLoc ; 

	double minVal ;
	double maxVal ;

public:
	virtual void AdjustToRoi( long timeMiliSec, Roi * imageRoi, Roi * targetRoi , double scaleFactor );
	virtual Disp * GetDisp() ; 

};

