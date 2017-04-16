
/* Name : Avinash Singh
 * File : passenger.h
 * Course : oop244 - workshop4 - at_home
 */
#ifndef HOLIDAY_PASSENGER_H_
#define HOLIDAY_PASSENGER_H_

#include<cstring>
namespace holiday{




	class Passenger {

	private:
		char m_name[32];
		char m_destination[32];
		int m_departureYear;
		int m_departureMonth;
		int m_departureDay;
	public:

		Passenger(const char*,const char*,const int,const int,const int);
		void travelWith(const Passenger*,int);
		void display(bool onlyNames = false) const;
		Passenger();
		Passenger(const char *,const char *);
		bool isEmpty() const;
		void setter();
		bool canTravelWith(const Passenger&) const;
		~Passenger(){};



	};
}

#endif


