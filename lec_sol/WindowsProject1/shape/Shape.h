#pragma once
#include "ComObject.h"
#include "Point.h"

#include <windows.h>
#include <d2d1.h>

class Shape abstract : public ComObject
{
public:
	Shape();
	~Shape();
public : 
	Point center; 
public :
	virtual void draw(ID2D1HwndRenderTarget * target) = 0 ;
};

