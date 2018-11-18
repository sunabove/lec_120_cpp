#pragma once

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <byteswap.h>

class ShapeCom
{
public:
	ShapeCom();
	virtual ~ShapeCom();
};

