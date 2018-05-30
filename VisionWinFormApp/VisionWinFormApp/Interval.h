#pragma once

#include <Windows.h>

class Interval
{
public:
	Interval(void);
	~Interval(void);

private:
	long diffMiliSum ; 

public:

	DWORD then;
	DWORD now; 

public: 
	void init();

	void setThen() ;
	void setNow() ;
	
	double getDiffSec() ;
	DWORD  getDiffMiliSec() ; 

};

