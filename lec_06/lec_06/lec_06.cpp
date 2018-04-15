// lec_06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <string>

using namespace std;

typedef int number;
typedef number Money;

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

const char * getMyName() {
	const char * name = "John";
	return name; 
}

int main() {
	int x = 1;
	x = f(x);
	printf("x = %d", x);

	const char * john = getMyName();

	printf("\n name = %s", john);

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
