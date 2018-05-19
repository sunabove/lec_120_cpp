#pragma once
#include "Shape.h"
class Point :
	public Shape
{
public:
	Point();
	~Point();

public:
	double x;
	double y;
};

