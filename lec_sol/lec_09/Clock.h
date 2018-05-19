#pragma once
class Clock
{
public:   static int clockCount; 

private:
	int hr;
	int min;
	int sec;
public:
	Clock();
	Clock(int hr, int min, int sec);
	~Clock();
public:
	void setTime(int hr, int min, int sec);
	void getTime(int * hr, int * min, int * sec);
	int getHr();
	int getMin();
	int getSec();

};

