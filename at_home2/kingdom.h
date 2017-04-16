// OOP244 Workshop 02: Dynamic Memory
// File kingdom.h
// Version 1.0
// Date 23-JAN-2017
// Author: Avinash Singh
// Description
// Dynamic Memory
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////


//header safeguards
#ifndef WESTEROS_KINGDOM_H_
#define WESTEROS_KINGDOM_H_


//westeros namespace
namespace westeros {

	class Kingdom {
	public:
		char m_name[32];
		int m_population;
	};
	void display(Kingdom&);
	void display(Kingdom [],int);
	void display(Kingdom [],int,int);
	void display(Kingdom [],int,const char []);
}
#endif
