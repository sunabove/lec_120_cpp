// lec_09.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#include "Employee.h"
#include "Clock.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Sqaure.h"

void pressAnyKeyToContinue() {
	FILE * out = stdout;
	fflush(out);
	fprintf(out, "\nEnter any key to continue. ");

	_getch();
}

int main(int argc, char ** argv ) {
	FILE * out = stdout;

	fprintf(out, "Hello....\n" );

	Employee employee;
	employee.name.first = "sun";
	employee.name.last = "above";

	fprintf(out, "first name : %s", employee.name.first.c_str());
	fprintf(out, "\nlast  name : %s", employee.name.last.c_str());

	if (true) {
		Clock myClock;
		Clock yourClock(12, 30, 20);
		myClock = yourClock;
	}

	pressAnyKeyToContinue();

	Circle cirle;
	Rectangle rect;
	rect.setWidth(100);
	rect.setHeight(200);

	Sqaure square;
	square.setWidth( 10 );

    return 0;
}

