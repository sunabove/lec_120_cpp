#pragma once
class Clock
{
private:
	int hr;
	int min;
	int sec;
public:
	Clock();
	~Clock();
public:
	void setTime(int hr, int min, int sec);
	void getTime(int * hr, int * min, int * sec);
	int getHr();
	int getMin();
	int getSec();

};

