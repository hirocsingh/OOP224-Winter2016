// OOP244 Workshop 03: Dynamic Memory
// File - Weather.h
// Version 1.0
// Date ???????????
// Author - Avinash Singh
////////////////////////

// compilation safegaurds
#ifndef SICT_WEATHER_H_
#define SICT_WEATHER_H_


/*Weather.h*/
// sict namespace
namespace sict {
    class Weather {
    	private :
    		char date[7];
    		double high_temp;
    		double low_temp;
    	public :

    		void set(const char *str, double, double);
    		void display() const;

    };
}


#endif
