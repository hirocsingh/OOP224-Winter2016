// OOP244 Workshop 5: operators overloading
// File: Fraction.h
// Version: 1.0 at home
// Date: 2017/02/14
// Author: Avinash Singh

#ifndef SICT_Fraction_H__
#define SICT_Fraction_H__

#include <iostream>

using namespace std;

namespace sict{
   
   class Fraction{
    private:

   		int num;			    // Numerator
   		int denom;			  // Denominator

   		int gcd();			  // returns the greatest common divisor of num and denom
   		void validate(int , int );
   		void safe();
      int max();        // returns the maximum of num and denom
      int min();        // returns the minimum of num and denom
   
    public:

        void reduce();     // simplifies a Fraction number by dividing the
                           // numerator and denominator to their greatest common divisor

        Fraction();                             // default constructor
      	Fraction(int n , int d=1); 		         // construct n/d as a Fraction number

        void display() const;

        bool isEmpty() const;     
    
        // member operator functions
        // TODO: write the prototype of member operator+= function HERE
        Fraction& operator+=(const Fraction& F);
        // TODO: write the prototype of member operator+ function HERE
        Fraction operator+(const Fraction& F) const;
        // TODO: write the prototype of member operator* function HERE
        Fraction operator*(const Fraction& F) const;


        // TODO: write the prototype of member operator== function HERE
        bool operator==(const Fraction&) const;
        // TODO: write the prototype of member operator!= function HERE
        bool operator!=(const Fraction&) const;
        // TODO: write the prototype of member operator double () function HERE
        operator double() const;
        // TODO: write the prototype of member operator int () function HERE
        operator int() const;
   };
};
#endif
