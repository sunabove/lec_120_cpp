#pragma once

#include <opencv2\opencv.hpp> 

class ViPoint : public cv::Point
{
public:
	ViPoint(void);
	~ViPoint(void);

public:
	bool selected;

public:

	int Distum( int x, int y );

	int Distum( cv::Point * p );

	bool IsSelected( int x, int y , int minDistum ) ;

};

