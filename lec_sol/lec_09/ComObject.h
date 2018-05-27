#pragma once

#define ZF_LOG_LEVEL ZF_LOG_INFO
#define ZF_LOG_TAG "MAIN"
#include "zf_log.h"

#include <stdio.h>
#include <stdarg.h>
#include <string>

class ComObject abstract
{
public: static int LAST_ID ;

public:
	int id;

public:
	ComObject();
	virtual ~ComObject() = 0 ;

};

