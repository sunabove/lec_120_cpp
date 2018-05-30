#pragma once

class ComObject
{
public:
	ComObject(void);
	~ComObject(void);

public:

	static void formatHMS( char * buff , size_t buffSize, int diff_ms ) ;

};

