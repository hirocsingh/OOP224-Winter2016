/* Name : Avinash Singh
 * File : passenger.cpp
 * Course : oop244 - workshop4 - in_lab
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include"passenger.h"


using namespace std;


namespace holiday{
	//default (no-argument) constructor.
	Passenger::Passenger(){
			setter();
		}

	//setter function to set class properties to safe empty state.
	void Passenger::setter() {
			m_name[0] = '\0';
			m_destination[0] = '\0';
			m_departureYear = 0;
			m_departureMonth = 0;
			m_departureDay = 0;
	}
	//2 Argument Constructor.
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

	//5-argument constructor for validation.
	Passenger::Passenger(const char name[],const char dest[],const int year,const int month,const int day){

		//validating properties of Passengers.
		if(name != nullptr && name[0] != '\0' && dest != nullptr && dest[0] != '\0'
				&& (year == 2017 || year == 2018 || year == 2019 || year == 2020)
				&& (month >= 1 && month <= 12)
				&& (day >= 1 && day <= 31)){
						strcpy(m_name,name);
						strcpy(m_destination,dest);
						m_departureYear = year;
						m_departureMonth = month;
						m_departureDay = day;
		}
		else
						setter();
	}

	//travelWith function.
	void Passenger::travelWith(const Passenger* arrPassenger,int size){
		int i,count=0;
		bool travel[size];
		fill_n(travel,size,false);
		//looping through passenger array to see who can travel with this passenger.
		for(i=0;i<size;i++){
						if(canTravelWith(arrPassenger[i])){
							travel[i] = true;
							count++;
						}
		}
		//if no one can travel with this passenger.
		if((arrPassenger == nullptr && size == 0) || count == 0)
					cout << "Nobody can join " << this->m_name << " on vacation!";
		else{

		//if everyone can join this passenger on the trip
		if(count == size)
			cout << "Everybody can join " << m_name << " on vaction!\n";

		cout << this->m_name << " will be accompanied by ";
		for(i=0;i<size;i++){
			if(travel[i])
				cout << arrPassenger[i].m_name << ((i==size-1)?".":",");
		}
		}
		cout << endl;
	}

	//comparing destination and date to see if a passenger can travel with other pasenger or not.
	bool Passenger::canTravelWith(const Passenger& p) const{
		if(strcmp(m_destination,p.m_destination)==0
		&& (m_departureDay == p.m_departureDay)
		&& (m_departureMonth == p.m_departureMonth)
		&& (m_departureYear == p.m_departureYear))
			return true;
		else
			return false;

	}

	//isEmpty() to check if Passenger Properties are in safe empty state or not.
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
