#pragma once
#include "Shape.h"
#include "Point.h"
class Circle :
	public Shape
{
public:
	Circle();
	~Circle();
private:
	Point center;
	double radius;
};

