// lec_04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <cmath>
#include <stdio.h>

using namespace std;  

int main(int argc, char ** argv)
{
	FILE * out = stdout;

	fprintf(out, "Hello World!");
	fprintf(out, "\nprintf format specifier example program.\n");

	fprintf(out, "\n\e[1mbold\e[0m");
	fprintf(out, "\n\e[4munderline\e[0m");
	fprintf(out, "\n\e[31mHello World\e[0m");
	fprintf(out, "\n\e[9mstrikethrough\e[0m");
	fprintf(out, "\n\e[3mitalic\e[0m");

	fprintf(out, "\n\nGood bye!");

	fprintf(out, "\nEnter any key to quit this program, please! ");

	_getch();

    return 0;
}

