#pragma once
#include "ShapeCom.h"
#include "MainFileHeader.h"

class ShapeFile :
	public ShapeCom
{
public:
	ShapeFile();
	virtual ~ShapeFile();

public:
	MainFileHeader mainFileHeader;
};

