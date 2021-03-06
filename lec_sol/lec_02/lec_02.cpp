//**************************************************************
// Given the length and width of a rectangle, this C++ program
// computes and outputs the perimeter and area of the rectangle.
//**************************************************************

#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace std; 

typedef double Area;
typedef double Side;
typedef double Perimeter;

int main(int argc, char ** argv) {
	Side length_m;
	Side width_m;
	Area area_m2;
	Perimeter perimeter_m;
	
	cout << "Program to compute and output the perimeter and "
		<< "area of a rectangle." << endl;

	length_m = 6.0;
	width_m = 4.0;
	perimeter_m = 2 * (length_m + width_m);
	area_m2 = length_m * width_m;
	
	cout << "Length = " << length_m << " meter" << endl;
	cout << "Width = " << width_m << " meter" << endl;
	cout << "Perimeter = " << perimeter_m << " meter" << endl;
	cout << "Area = " << area_m2 << " meter^2" << endl;

	cout << "Enter any key to quit, please! ";
	_getch();

	return 0;
}