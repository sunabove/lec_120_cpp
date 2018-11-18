#pragma once
#include "ShapeCom.h"
class MainFileHeader :
	public ShapeCom
{
public:
	MainFileHeader();
	virtual ~MainFileHeader();

public: 
	int32_t fileCode;

	int32_t unused_1;
	int32_t unused_2;
	int32_t unused_3;
	int32_t unused_4;
	int32_t unused_5; 

	int32_t fileLength;

	int32_t version;
	int32_t shapeType;
};

