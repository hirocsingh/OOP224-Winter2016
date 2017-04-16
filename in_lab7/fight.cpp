///////////////////////////////
//  Workshop 7
// Derived classes
//
// fight.cpp for in-lab portion
// by Avinash Singh
// 1.0
// Copyright 2017 Seneca College

#include <iostream>
#include "Hero.h"
#include "fight.h"


using namespace std;

//////////////////////
// Global helper function
// compute the damage that A inflicts on B 
// and of B on A
//
void apply_damage (Hero& A, Hero& B)
{
	if(A.m_health >= 0 || B.m_health >= 0){
		A.m_health -= B.m_attack;
		B.m_health -= A.m_attack;
	}
}



//////////////////////////////////////////////////////////////////
// Global helper operator
// rather than type in fight(hercules, theseus), we use an operator
// so you can type in hercules * theseus
//
// returns a reference to the winner object
// 
// so that if hercules is stronger, 
// (hercules * theseus) == hercules
// will be true.
// 
// note the inputs are const, so that you can be sure that the heros will be unharmed during the fight.
//
const Hero & operator* (const Hero & first, const Hero & second)
{


    // Display the names of the people fighting

    cout << "AncientBattle! ";
    first.display (cout);
    cout << " vs ";
    second.display (cout);
    cout << " : ";


    // We want our heroes to exit the battle unharmed, so 
    // we make the input arguments const.
    // So how can we modify the objects during the fight?
    // We make copies of them.
    Hero A = first;
    Hero B = second;
    const Hero *winner = nullptr;

    // Now A will fight B, and *winner will point to the winner.    
    // Main fight loop
    unsigned int rounds = 0;
    // loop while both are still alive
    // fight for 100 rounds
    while (A.isAlive () && B.isAlive () && rounds < 100)
    {
        rounds++;
        apply_damage(A, B);
    }
    
    // if we got here, then one Hero is dead, or if both are alive then it was a draw.
    bool draw;
    
    if (A.isAlive() && B.isAlive())     {   draw = true;    }
    else                                {   draw = false;   }
  
    // if it was a draw, then we decide by tossing an unfair coin and always
    // declare that A was the winner. 
    if (draw)                   
    {   winner = &first;     }
    else if (A.isAlive ())      
    {   winner = &first;     }
    else                        
    {   winner = &second;    }

    // print it out
    cout << "Winner is ";
    winner->display(cout);
    cout << " in " << rounds << " rounds." << endl;
    return *winner;

}


