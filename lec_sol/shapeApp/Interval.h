#pragma once
#include "ShapeCom.h"
class Interval :
	public ShapeCom
{
public:
	Interval();
	virtual ~Interval();

public:
	double min;
	double max;
};

