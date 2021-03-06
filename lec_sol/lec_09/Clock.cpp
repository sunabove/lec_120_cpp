#include "stdafx.h"
#include "Clock.h"
#include <stdio.h>

int Clock::clockCount = 0;

Clock::Clock() {
	//constructor
	fprintf( stdout, "\nA default construtor was called.");

	Clock::clockCount++;
}

Clock::Clock(int hr, int min, int sec) {
	//custom constructor
	this->hr = hr;
	this->min = min;
	this->sec = sec;

	Clock::clockCount++;
}


Clock::~Clock() {
	//destructor
	fprintf( stdout, "\nA desctuctor was called.");

	Clock::clockCount--;
}

void Clock::setTime(int hr, int min, int sec) {
	fprintf( stdout, "\nA cusotm constructor was called.");
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
