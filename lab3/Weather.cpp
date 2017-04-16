/*Weather.cpp*/
#include<iostream>
#include<iomanip>
#include "Weather.h"
using namespace std;


namespace sict {
	void Weather::set(const char* str, double high, double low) {
		strcpy(date,str);
		high_temp = high;
		low_temp = low;
	}

	void Weather::display() const {
		cout << left << setfill('_') << setw(10) << date;
		cout << right << setfill('_') << setw(6) << high_temp;
		cout << right << setfill('_') << setw(6) << low_temp << endl;


	}
}


/*
Weather Data
=====================
Days of Weather: 3
Enter date: Oct/1
Enter high: 15
Enter low : 10
Enter date: Nov/13
Enter high: 10
Enter low : 1.1
Enter date: Dec/15
Enter high: 5.5
Enter low : -6.5
Weather report:
Date        high   low
======================
Oct/1_______15.0__10.0
Nov/13______10.0___1.1
Dec/15_______5.5__-6.5
*/
