#pragma once
#include "ComObject.h"

#include <windows.h>
#include <d2d1.h>

class Point : public ComObject 
{
public:
	Point();
	~Point();

public:
	float x;
	float y;
public:
	virtual void draw(ID2D1HwndRenderTarget * target);
};

