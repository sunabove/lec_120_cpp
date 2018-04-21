// lec_07.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int mainNewtonRaphson(int argc, char ** argv);

size_t sizeOfArray(int a []) {
	return sizeof(a);
}

int main(int argc, char ** argv) {
	mainNewtonRaphson(argc, argv);

	return 0;
}

int main_old( int argc, char ** argv ) {
	FILE * out = stdout;
	const char * LINE = "\n**********************************************************";
	fprintf(out, LINE);
	fprintf(out, "\n Array ");
	fprintf(out, LINE);
	fprintf(out, "\n" );
	
	if ( true ) {
		fprintf(out, "\n%s\n", LINE);
		int list[10];

		fprintf( out, "\nsize of array = %Iu", sizeof( list ));
		fprintf( out, "\nsize of array = %Iu", sizeOfArray( list ));

		for (int & x : list) {
			fprintf( out, "%d\n", x);
		}
		fprintf(out, "\n%s\n", LINE);
	}

	if (true) {
		fprintf(out, "\n%s\n", LINE);
		int list[10];
		int x;
		for (int i = 0; i < sizeof(list); i++) {
			x = list[i];
			fprintf( out, "%d\n", x);
		}
		fprintf(out, "\n%s\n", LINE);
	}

	if( true ) {
		fprintf(out, "\n%s\n", LINE);
		int list[10];
		int * p = list; 
		int x; 
		fprintf( out, "\nsize of   x = %zu", sizeof( x ));
		fprintf( out, "\nsize of * p = %zu", sizeof( int * ));
		for (int i = 0; i < sizeof(list); i++) {
			x = *p; 
			fprintf( out, "%d\n", x);
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
