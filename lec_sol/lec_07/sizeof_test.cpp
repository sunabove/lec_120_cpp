// lec_07.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

size_t getSizeOfArray(int a[]) {
	return sizeof(a);
}

int mainSizeOfTest(int argc, char ** argv) {

	FILE * out = stdout;
	const char * LINE = "\n**********************************************************";
	fprintf(out, LINE);
	fprintf(out, "\n Array ");
	fprintf(out, LINE);
	fprintf(out, "\n");

	if (false) {
		fprintf(out, "\n%s\n", LINE);

		int list[10];

		fprintf(out, "\n sizeof(list)         = %2zd", sizeof(list));
		fprintf(out, "\n getSizeOfArray(list) = %2zd", getSizeOfArray(list));
		fprintf(out, "\n array size           = %2zd", sizeof(list)/sizeof(list[0]));

		fprintf(out, "\n%s\n", LINE);

		int idx = 0; 
		for (int & x : list) {
			fprintf(out, "\n[%02d] x = %d", idx, x);
			idx++;
		}
		fprintf(out, "\n%s\n", LINE);
	}

	if (false) {
		fprintf(out, "\n%s\n", LINE);
		fprintf(out, "\n%s", "array for loop" );
		fprintf(out, "\n%s\n", LINE);
		int list[10];
		int x;
		// below code has some bugs which is should be modified.
		for (int i = 0; i < sizeof(list); i++) {
			x = list[i];
			fprintf(out, "\n[%02d] x = %d", i, x);
		}
		fprintf(out, "\n%s\n", LINE);
	}

	if (false) {
		fprintf(out, "\n%s\n", LINE);
		int list[10];
		int * p = list;
		int x;
		fprintf(out, "\nsize of   x = %zu", sizeof(x));
		fprintf(out, "\nsize of * p = %zu", sizeof(int *));
		for (int i = 0; i < sizeof(list); i++) {
			x = *p;
			fprintf(out, "%d\n", x);
			p++;
		}
		fprintf(out, "\n%s\n", LINE);
	}

	fprintf(out, LINE);
	fflush(out);
	fprintf(out, "\nEnter any key to continue. ");
	_getch();
	return 0;
}
// end of file
