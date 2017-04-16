///////////////////////////////
//  Workshop 7
// Derived classes
//
// fight.cpp for in-lab portion
// by Avinash Singh
// 1.0
// Copyright 2017 Seneca College

#ifndef SUPERHERO_H
#define SUPERHERO_H


#include "Hero.h"


class SuperHero: public Hero
{

    unsigned m_superPowerAttack;
    unsigned m_superPowerDefend;

public:

    // constructors  
    SuperHero();
    SuperHero(const char* name, 
            unsigned health, 
            unsigned attack,
            // the following 2 parameters are special for SuperHeros
            unsigned superPowerAttack, 
            unsigned superPowerDefend);

    unsigned getAttack() const;
        
        
    // friend global helper function to assign damage to 2 heroes at the same time.
    friend void apply_damage ( SuperHero& A,  SuperHero& B);
 
 
 };

#endif
