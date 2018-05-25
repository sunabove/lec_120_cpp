#pragma once

#include <stdio.h>
#include <string>

class ComObject
{
public: static int LAST_ID ;

public:
	int id;
public:
	ComObject();
	~ComObject();

public:
	void log(const char * msg);
	void log(std::string * msg);
};

