///////////////////////////////
//  Workshop 7
// Derived classes
//
// fight.cpp for in-lab portion
// by Avinash Singh
// 1.0
// Copyright 2017 Seneca College

#include <cstring>
#include <iostream>
#include "Hero.h"

using namespace std;


//////////////////////////////////////////////
// Default constructor
//
Hero::Hero ()
{
  m_name[0] = '\0';
  m_health = 0;
  m_maximumHealth = 0;
  m_attack = 0;
}


///////////////////////////////////////////////////
// Constructor
// 
Hero::Hero (const char name[], unsigned maximumHealth, unsigned attack)
{
 if(name != nullptr)
	 	strcpy(m_name,name);
 m_health = maximumHealth;
 m_maximumHealth = maximumHealth;
 m_attack = attack;
}



/////////////////////////////////////////////////////////
// 
// Hero::display function
void Hero::display (ostream & out) const 
{
	if(!this->isEmpty())
		out << m_name;
}



/////////////////////////////////////////////////
// Hero::isEmpty ()
// return true if the Hero object is uninitialized
//
bool Hero::isEmpty () const 
{
 return (m_name[0] == '\0' && m_health == 0 && m_maximumHealth == 0 && m_attack == 0);
}

/////////////////////////////////////////////////
// sets the Hero object's health back to full
//
void Hero::respawn() 
{
	m_health = m_maximumHealth;
}

