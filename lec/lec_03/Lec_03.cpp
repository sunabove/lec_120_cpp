// Lec_03.cpp : Defines the entry point for the console application. 
#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std ; 

int main(int argc, char ** argv)
{
	cout << "Hello!" << endl; 

	char c = 0x41 ; 

	cout << "siz of " << c << " " << typeid(c).name() << " : " << sizeof(c) << endl ;

	wchar_t wc = L'가'; 

	cout << "size of " << wc << " " << typeid(wc).name() << " : " << sizeof(wc) << endl;

	int feet;
	int inches;
	cout << "Enter two integers separated by one or more spaces: ";
	cin >> feet >> inches;
	cout << endl;
	cout << "Feet = " << feet << endl;
	cout << "Inches = " << inches << endl;

	cerr << endl << "Enter any key to quit, please! ";

	_getch();

    return 0;
}

