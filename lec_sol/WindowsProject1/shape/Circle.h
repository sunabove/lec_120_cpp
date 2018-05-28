#pragma once
#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
public:
	Circle();
	~Circle();
public:
	float radius;
public:
	virtual void draw(ID2D1HwndRenderTarget * target);
};

