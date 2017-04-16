/* Name : Avinash Singh
 * File : passenger.cpp
 * Course : oop244 - workshop4 - in_lab
 */
#include<iostream>
#include<cstring>
#include"passenger.h"


using namespace std;


namespace holiday{

	Passenger::Passenger(){
			setter();
		}
	void Passenger::setter() {
			m_name[0] = '\0';
			m_destination[0] = '\0';
			m_departureYear = 0;
			m_departureMonth = 0;
			m_departureDay = 0;
	}
	Passenger::Passenger(const char name[],const char destination[]){

		if(name != nullptr && name[0] != '\0' && destination != nullptr && destination[0] != '\0'){
				strcpy(m_name,name);
				strcpy(m_destination,destination);
				m_departureDay = 1;
				m_departureMonth = 7;
				m_departureYear = 2017;
		}
		else
			setter();



	}

	bool Passenger::canTravelWith(const Passenger& p) const{
		if(strcmp(m_destination,p.m_destination)==0
		&& (m_departureDay == p.m_departureDay)
		&& (m_departureMonth == p.m_departureMonth)
		&& (m_departureYear == p.m_departureYear))
			return true;
		else
			return false;

	}


	bool Passenger::isEmpty() const{
		if((m_name[0] == '\0')
			&& (m_destination[0] == '\0')
			&& (m_departureYear == 0)
			&& (m_departureMonth == 0)
			&& (m_departureDay == 0))
			return true;
		else
			return false;
	}

	void Passenger::display(bool nameOnly) const
	{
		if (false == this->isEmpty())
		{
			cout << this->m_name;
			if (false == nameOnly)
			{
				cout << " will travel to " << this->m_destination << ". "
				     << "The journey will start on "
				     << this->m_departureYear << "-"
					 << this->m_departureMonth << "-"
					 << this->m_departureDay
				     << "." << endl;
			}
		}
		else
		{
			cout << "Invalid passenger!" << endl;
		}

	}


}

