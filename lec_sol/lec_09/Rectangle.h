#pragma once
#include "Shape.h"
class Rectangle :
	public Shape
{
public:
	Rectangle();
	~Rectangle();
protected:
	double width;
	double height;

public:
	void setWidth(int width);
	void setHeight(int height);
};

