#pragma once
#include "comobject.h"

#include <opencv2\opencv.hpp> 

#include "VisionInterface.h"

class Style :
	public ComObject, VisionInterface
{
public:
	Style(void);
	~Style(void);
};

