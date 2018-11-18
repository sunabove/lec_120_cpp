#pragma once
#include "ShapeCom.h"
#include "Interval.h"

class Box :
	public ShapeCom
{
public:
	Box();
	virtual ~Box();

public:
	Interval x;
	Interval y;
	Interval z;
	Interval m;
};

