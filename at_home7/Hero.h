///////////////////////////////
//  Workshop 7
// Derived classes
//
// fight.cpp for in-lab portion
// by Avinash Singh
// 1.0
// Copyright 2017 Seneca College

#ifndef HERO_H
#define HERO_H

#include <iostream>

class Hero
{
    char m_name[41];
    unsigned m_attack;
    unsigned m_maximumHealth;

    bool isEmpty () const;
protected:
    int m_health;

public:
    Hero ();
    Hero (const char name[], unsigned maximumHealth, unsigned attack);


    void respawn();
    bool isAlive () const  	        {    return m_health > 0;  	}
    unsigned getAttack () const     {    return m_attack;  		}	

    // display function
    void display (std::ostream &) const;

    friend void apply_damage ( Hero& A,  Hero& B);
};


 


#endif
