#pragma once
#include "ComObject.h"

class Shape abstract : public ComObject
{
public:
	Shape();
	~Shape();
public:
	virtual void draw() = 0 ;
};

