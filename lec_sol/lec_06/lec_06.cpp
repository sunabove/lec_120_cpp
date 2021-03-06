// lec_06.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <conio.h>
#include <string>

using namespace std;

typedef int number;
typedef number Money;

// variable life cycle
int f(int x) {
	x++;
	return x;
}

// overloading function 
void g(int x) { }
void g(int x, double y) {}
//void g(int x, double z) {}
void g(float y, int x) {} 
void g(double y, int x) {}
// -- overloading function 

const char * getName() {
	const char * name = "John";
	return name; 
}

const char * getCharName() {
	char n[ 5 ] = { 'J' , 'o', 'h', 'n' , '\0' };
	return n; 
}

string * getStrName() {
	string name = "Olive";
	return &name; 
}

int main() {
	FILE * out = stdout; 
	int x = 1;
	x = f(x);
	fprintf( out, "x = %d", x);
	fflush( out );

	const char * john = getName();
	fprintf( out, "\nName = %s", john);
	fflush( out );

	const char * charName = getCharName();
	fprintf( out, "\nChar Name = %s", john);
	fflush( out );

	if (true) {
		string name = "olive";
		string * olive = &name;
		fprintf(out, "\nStr Name = %s", olive->c_str());
		fflush(out);
	}

	if (true) {
		string * olive = getStrName();
		fprintf(out, "\nStr Name = %s", olive->c_str());
		fflush(out);
	}

	// pointer
	if (true) {
		char c = 'A';
		char * s = &c;
		char ** t = &s;

		(*s) = 'B';
	}

	// reference
	if (true) {
		char c = 'A';
		char & s = c;
		char && t = 'A' ;

		printf("%c", t);

		s = 'B';
	}

	// Enumeration
	enum Grade { A = 'A', B = 'B' , C, D, F };

	Grade g = A;

	printf("\nEnter any key to continue. ");

	_getch();
    return 0;
}
// end of file
