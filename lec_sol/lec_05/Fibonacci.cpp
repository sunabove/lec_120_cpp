// lec_05.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <locale.h>

// 변수형 크기 참고 URL
// https://msdn.microsoft.com/en-us/library/cc953fe1.aspx

//typedef unsigned int number; // 4 byte
//typedef unsigned long number; // 4 byte
typedef unsigned long long number; // 8 byte

int main(int argc, char ** argv)
{
	printf("Fibonacci sequence by Numerical Solution");

	printf("\nsizeof number : %zu", sizeof(number));
	printf("\nEnter any key to continue ... ");
	_getch();

	number a1 = 1;
	number a2 = 1;
	number a3 = a2 + a1;

	number a3Prev = a3;
	unsigned int index = 1;
	printf("\na[%3zu] = %26zu", index++, a1);
	printf("\na[%3zu] = %26zu", index++, a2);

	do {
		printf("\na[%3zu] = %26zu", index++, a3);
		a3Prev = a3; 
		a1 = a2;
		a2 = a3; 
		a3 = a2 + a1; 
	} while ( a3Prev < a3 );

	printf("\nEnter any key to quit! ");
	_getch();

    return 0;
}

