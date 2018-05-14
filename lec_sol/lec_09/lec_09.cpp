// lec_09.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#include "Employee.h"

void pressAnyKeyToContinue() {
	FILE * out = stdout;
	fflush(out);
	fprintf(out, "\nEnter any key to continue. ");

	_getch();
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* locale = setlocale(LC_ALL, "Korean"); // Get the CRT's current locale.
	std::locale lollocale(locale);
	setlocale(LC_ALL, locale); // Restore the CRT.

	Employee employee;
	employee.name.first = L"병문";
	employee.name.last = L"성";

	FILE * out = stdout;

	fwprintf(out, L"first name : %s", employee.name.first.c_str());
	fwprintf(out, L"\nlast  name : %s", employee.name.last.c_str());

	pressAnyKeyToContinue();

    return 0;
}

