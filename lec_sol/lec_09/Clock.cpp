#include "stdafx.h"
#include "Clock.h"


Clock::Clock() {
}


Clock::~Clock() {
}

void Clock::setTime(int hr, int min, int sec) {
	this->hr = hr;
	this->min = min;
	this->sec = sec;
}

void Clock::getTime(int * hr, int * min, int * sec) {
	*hr = this->hr;
	*min = this->min;
	*sec = this->sec;
}

int Clock::getHr() {
	return hr;
}

int Clock::getMin() {
	return this->min;
}

int Clock::getSec() {
	return this->sec;
}
