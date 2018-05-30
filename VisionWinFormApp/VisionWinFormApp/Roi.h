#pragma once

#include <opencv2\opencv.hpp>

#include "ViPoint.h"

public class Roi 
{

public:
	Roi(void);
	~Roi(void);

private:

	bool valid ;
	cv::Rect rect ; 

	ViPoint center ; 

public: 

	bool fixed ;
	bool selected ; 
	bool mouseDragging ;  

	ViPoint leftTop ;
	ViPoint rightBottom ; 

	bool simpleRect ; 

public: 

	virtual void InitData( bool locInit ) ; 

	virtual cv::Rect * GetRect() ;

	virtual ViPoint * GetCenter();

	virtual void SetCenter( int cx, int cy );

	virtual bool isValid() ; 

	virtual void InValidte() ;

	virtual void UnSelected() ;

	virtual bool IsSelected(int x, int y) ; 

};