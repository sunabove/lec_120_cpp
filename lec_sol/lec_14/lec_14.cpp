// lec_14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

// compile with: /EHsc  
#include <vector>  
#include <list>  
#include <iostream>

void pressAnyKeyToContinue() {
	FILE * out = stdout;
	fflush(out);
	fprintf(out, "\nEnter any key to continue. ");

	_getch();
}

int vectorExample() {  
	using namespace std;  
	vector<int> v1, v2, v3;  

	v1.push_back(10);  
	v1.push_back(20);  
	v1.push_back(30);  
	v1.push_back(40);  
	v1.push_back(50);  

	cout << "v1 = ";  
	for (auto& v : v1){  
		cout << v << " ";  
	}  
	cout << endl;  

	v2.assign(v1.begin(), v1.end());  
	cout << "v2 = ";  
	for (auto& v : v2){  
		cout << v << " ";  
	}  
	cout << endl;  

	v3.assign(7, 4);  
	cout << "v3 = ";  
	for (auto& v : v3){  
		cout << v << " ";  
	}  

	v3.assign({ 5, 6, 7 });  
	for (auto& v : v3){  
		cout << v << " ";  
	}  
	cout << endl;

	return 0;
}  

int listExample()  
{  
	using namespace std;  
	list<int> c1, c2;  
	list<int>::const_iterator cIter;  

	c1.push_back(10);  
	c1.push_back(20);  
	c1.push_back(30);  
	c2.push_back(40);  
	c2.push_back(50);  
	c2.push_back(60);  

	cout << endl;  
	cout << "c1 =";  
	for (auto c : c1)  
		cout << " " << c;  
	cout << endl;  

	c1.assign(++c2.begin(), c2.end());  
	cout << "c1 =";  
	for (auto c : c1)  
		cout << " " << c;  
	cout << endl;  

	c1.assign(7, 4);  
	cout << "c1 =";  
	for (auto c : c1)  
		cout << " " << c;  
	cout << endl;  

	c1.assign({ 10, 20, 30, 40 });  
	cout << "c1 =";  
	for (auto c : c1)  
		cout << " " << c;  
	cout << endl;  
	return 0;
}  

int main()
{
	vectorExample();
	pressAnyKeyToContinue();

	listExample();
	pressAnyKeyToContinue();
	pressAnyKeyToContinue();

    return 0;
}

