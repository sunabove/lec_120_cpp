// lec_05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

// 변수형 크기 참고 URL
// https://msdn.microsoft.com/en-us/library/cc953fe1.aspx

//typedef unsigned int number; // 4 byte
//typedef unsigned long number; // 4 byte
typedef unsigned long long number; // 8 byte

int main(int argc, char ** argv)
{
	printf("Fibonacci sequence by Numerical Solution");

	number a1 = 1;
	number a2 = 2;
	number a3 = a2 + a1 ; 

	printf("\nsizeof number : %d", sizeof(number));
	printf("\nEnter any key to continue ... ");
	_getch();

	number a3Prev = a3; 
	unsigned int index = 0;
	do {
		printf("\na[%zu] = %zu", (index + 3), a3);
		a3Prev = a3; 
		a1 = a2;
		a2 = a3; 
		a3 = a2 + a1;
		index++;
	} while ( a3Prev < a3 );

	printf("\nEnter any key to quit! ");
	_getch();

    return 0;
}

