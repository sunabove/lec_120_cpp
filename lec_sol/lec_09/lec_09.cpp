// lec_09.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#include "Employee.h"
#include "Clock.h"

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
		Clock clock;
		Clock clock2(); // illegal
	}

	pressAnyKeyToContinue();

    return 0;
}

