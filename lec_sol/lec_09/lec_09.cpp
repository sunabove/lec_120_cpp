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
	zf_log_set_output_level(ZF_LOG_WARN);

	FILE * out = stdout;

	fprintf(out, "Hello....\n" );

	if ( false ) {
		Employee employee;
		employee.name.first = "sun";
		employee.name.last = "above";

		fprintf(out, "first name : %s", employee.name.first.c_str());
		fprintf(out, "\nlast  name : %s", employee.name.last.c_str());

		Clock myClock;
		Clock yourClock(12, 30, 20);
		myClock = yourClock;

		pressAnyKeyToContinue();
	}

	if (true) {
		Rectangle rect;
		rect.setWidth(100);
		rect.setHeight(200);

		Rectangle rect2 = rect;

		rect.draw();

		Circle c;
		c.draw();
	}

	pressAnyKeyToContinue();

    return 0;
}

