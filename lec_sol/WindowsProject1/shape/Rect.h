#pragma once
#include "Shape.h"
class Rect : public Shape
{
public:
	Rect();
	Rect(const Rect & rect);
	virtual ~Rect();

public:
	float width;
	float height;

public:
	void draw();
	virtual void draw(ID2D1HwndRenderTarget * target);
};

