// OOP244 Workshop 02: Dynamic Memory
// File kingdom.cpp
// Version 1.0
// Date 23-JAN-2017
// Author Avinash Singh
// Description
// Dynamic memory
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
#include<iostream>
#include"kingdom.h"

using namespace std;

void westeros::display(Kingdom& king_name) {

	cout << king_name.m_name <<","<<"population "<<king_name.m_population<<endl;

	}

void westeros::display(Kingdom kingdom_[],int size) {
	int i,total_pop = 0;
	cout <<"------------------------------"<<endl;
	cout <<"Kingdoms of Westeros"<<endl;
	cout <<"------------------------------"<<endl;
	for(i=0; i<size; i++) {
		total_pop = total_pop + kingdom_[i].m_population;
		cout <<i+1<<". "<< kingdom_[i].m_name <<","<<" population "<<kingdom_[i].m_population<<endl;
	}

	cout <<"------------------------------\n";
	cout <<"Total population of Westeros: "<<total_pop<<endl;
	cout <<"------------------------------\n";

}

void westeros::display(Kingdom _kingdom[],int size,int min_pop) {
	int i;
	cout <<"------------------------------\n";
	cout <<"Kingdoms of Westeros with more than "<<min_pop<<" people\n";
	cout <<"------------------------------\n";
	for(i=0; i<size; i++) {
			if(_kingdom[i].m_population >= min_pop)
				cout <<i+1<<". "<< _kingdom[i].m_name <<","<<" population "<<_kingdom[i].m_population<<endl;
		}
	cout <<"------------------------------\n";
}

void westeros::display(Kingdom _kingdom2[],int size,const char m__name[32]) {
	int i;
	bool flag = false;
	cout <<"------------------------------\n";
	cout <<"Searching for kingdom "<<m__name<<" in Westeros\n";
	cout <<"------------------------------\n";
	for(i=0; i<size; i++) {
		if(!strcmp(_kingdom2[i].m_name,m__name))
		{
			flag = true;
			break;
		}
	}
	if(flag)
		cout << m__name <<","<<" population "<<_kingdom2[i].m_population<<endl;
	else
		cout <<m__name<<" is not part of Westeros.\n";
	cout <<"------------------------------\n";


}


