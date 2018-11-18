#pragma once
#include "ShapeCom.h"
#include "Header.h"

class Shape : public ShapeCom
{
public:
	Shape();
	virtual ~Shape();

	Header header;
};

