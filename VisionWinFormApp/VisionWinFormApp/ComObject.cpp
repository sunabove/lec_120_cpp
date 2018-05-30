#include "StdAfx.h"
#include "ComObject.h"

#include <stdio.h>

ComObject::ComObject(void)
{
}


ComObject::~ComObject(void)
{
}

void ComObject::formatHMS( char * buff, size_t buffSize, int diff_ms ) { 

	const int diffSec = diff_ms/1000;

	int sec = diffSec % 60;
	int min = ( diffSec / 60 )%60 ;
	int hour = diffSec / 3600 ;

	sprintf_s( buff, buffSize, "%02d:%02d:%02d", hour, min, sec );
}
