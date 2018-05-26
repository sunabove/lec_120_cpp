#include "stdafx.h"
#include "ComObject.h"

int ComObject::LAST_ID = 0; 
ComObject::ComObject() {
	this->id = ComObject::LAST_ID++;
}

ComObject::~ComObject() {
}

void ComObject::log(const char * str) {
	fprintf(stdout, str);
	fprintf(stdout, "\r\n");
	fflush(stdout);
}

void ComObject::log(std::string * str) {
	this->log(str->c_str());
}
