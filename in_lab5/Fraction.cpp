// OOP244 Workshop 5: operators overloading
// File: Fraction.cpp
// Version: 1.0
// Date: 2017/02/13
// Author: Avinash Singh
#include "Fraction.h"

using namespace std;

namespace sict{
	void Fraction::safe(){
		denom = -1;
	}

	void Fraction::validate(int n,int d){
		if(n >= 0 && d > 0){
		            num = n;
		            denom = d;
		            reduce();
		        }
		else
			safe();
	}
    Fraction::Fraction(){  
            safe();
    }

    Fraction::Fraction(int n, int d) // n: numerator, d: denominator
    { 
        validate(n,d);
    }


    int Fraction::gcd()                                        // returns the greatest common divisor of num and denom 
    {
        int mn = min();                                        // min of num and denom
        int mx = max();                                        // mX of num and denom

        for (int x=mn ; x > 0 ; x--)                           // find the greatest common divisor
            if( mx % x == 0 &&  mn % x == 0)
                return x;
        return 1;

    } 

    void Fraction::reduce()                                         // simplify the Fraction number  
    {
        int tmp = gcd();
        num /= tmp;
        denom /= tmp;
    }

    int Fraction::max ()
    {
        return (num >= denom) ? num : denom; 
    }

    int Fraction::min()
    {
        return (num >= denom) ? denom : num; 
    }

    // in_lab

    // TODO: write the implementation of display function HERE
    void Fraction::display() const{
    	if(isEmpty())
    		cout << "Invalid Fraction Object";
    	else{
    		if(denom == 1)
    			cout << num << endl;
    		else
    			cout << num << "/" << denom;
    	}
    }

    // TODO: write the implementation of isEmpty function HERE
    bool Fraction::isEmpty() const{
    	return denom == -1;
    }

    // TODO: write the implementation of member operator+= function HERE
    Fraction& Fraction::operator+=(const Fraction& F){
    	*this = *this+ F;
    	return *this;
    }

    // TODO: write the implementation of member operator+ function HERE
    Fraction Fraction::operator+(const Fraction& F) const{
    	Fraction temp;
    	if(!isEmpty() && !F.isEmpty()){
    		temp.num = num*F.denom + denom*F.num;
    		temp.denom = denom*F.denom;
    	}
    	else
    		temp.safe();

    	return temp;

    }

    // TODO: write the implementation of member operator* function HERE
    Fraction Fraction::operator*(const Fraction& F) const{
    	Fraction temp;
    	    	if(!isEmpty() && !F.isEmpty()){
    	    		temp.num = num*F.num;
    	    		temp.denom = denom*F.denom;
    	    	}
    	    	else
    	    		temp.safe();

    	    	return temp;
    }

}


