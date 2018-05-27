#pragma once
#include "Rectangle.h"
class Sqaure :
	public Rectangle
{
public:
	Sqaure();
	~Sqaure();
public:
	void setWidth(int width);
	void setHeight(int height);
};

