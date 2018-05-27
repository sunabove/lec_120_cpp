#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle(const Rectangle & rectangle);
	virtual ~Rectangle();

public:
	double width;
	double height;

public:
	void setWidth(int width);
	void setHeight(int height);
	void draw();
};

