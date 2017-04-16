// OOP244 Workshop 5: operators overloading
// File: Fraction.cpp
// Version: 1.0 at home
// Date: 2017/02/14
// Author: Avinash Singh

#include "Fraction.h"

using namespace std;

namespace sict{
	void Fraction::safe(){
		denom = -1;
	}
	void Fraction::validate(int n, int d){
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
       validate(n,d);            // set to safe empty state
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

    void Fraction::display() const{
        	if(isEmpty())
        		cout << "Invalid Fraction Object";
        	else{
        		if(denom == 1)
        			cout << num;
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
        	*this = *this + F;
        	reduce();
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


        bool Fraction::operator==(const Fraction& F) const{
        	bool compare=false;
        	if(!this->isEmpty() && !F.isEmpty())
        		if((this->num * F.denom) == (this->denom * F.num))
        			compare = true;
        	return compare;

        }
        // TODO: write the prototype of member operator!= function HERE
        bool Fraction::operator!=(const Fraction& F) const{
        	bool compare = false;
        	if(!this->isEmpty() && !F.isEmpty())
        		if((this->num * F.denom) != (this->denom * F.num))
        	        		compare = true;
        	return compare;
        }
        // TODO: write the prototype of member operator double () function HERE
        Fraction::operator double() const{
        	double val = 0.0;
        	if(!this->isEmpty())
        		val = double(this->num) / double(this->denom);
        	else
        		val = -1.0;
        	return val;
        }
        // TODO: write the prototype of member operator int () function HERE
        Fraction::operator int() const{
        	int val = 0;
        	if(!this->isEmpty())
        	        val = this->num / this->denom;
        	else
        	        val = -1;
        	return val;
        }


}
