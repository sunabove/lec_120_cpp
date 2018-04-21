// lec_07.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef double number;

const number epsilon = 0.000000001;
const number e = epsilon;

number f(number x) {
	return x * x - 4;
}

number derivative(number x) {
	number der = (f(x + e) - f(x)) / e;
	return der;
}

int mainNewtonRaphson( int argc, char ** argv ) {
	FILE * out = stdout;
	const char * LINE = "\n**********************************************************";
	fprintf(out, LINE);
	fprintf(out, "\n     Newton-Raphson Method Program");
	fprintf(out, LINE);

	number x = 1.0e7;
	number y ;
	int index = 0;

	do {
		y = f(x);
		fprintf(out, "\n[%03d] f(%.20f) = %.20f", (index + 1 ), x, y);
		x = x - (y / derivative(x));
		index++;
	} while (y > epsilon || -y > epsilon);

	fprintf(out, LINE);
	fflush(out);
	fprintf(out, "\nEnter any key to continue. ");
	_getch();

	return 0;
}
// end of file
