#pragma once
#include "ComObject.h"

class Shape : public ComObject
{
public:
	Shape();
	~Shape();
public:
	virtual void draw() = 0 ;
};

