#pragma once

#include <string>
using namespace std;

struct Name {
	string first;
	string middle;
	string last;
};

struct Address {
	string address;
	string city;
	string state;
	string zip;
};

struct Date {
	int month;
	int day;
	int year;
};

struct Employee {
	Name name;
	string empID;
	Address address;
	Date hireDate;
};

//