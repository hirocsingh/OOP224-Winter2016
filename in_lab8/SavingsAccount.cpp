/* Name : Avinash Singh
 * OOP244 Section B
 * Workshop8
 * 20 - March - 2017
 */

#include "SavingsAccount.h"
#include<iomanip>
using namespace std;

namespace ict{

	// TODO: Implement SavingsAccount member functions here
	SavingsAccount::SavingsAccount(double bal, double int_rate) : Account(bal){
		if(int_rate < 0)
			interestRate = 0.0;
		else
			interestRate = int_rate;


	}
    double SavingsAccount::calculateInterest(){
    	return interestRate * getBalance();
    }

    std::ostream& SavingsAccount::display(std::ostream& os)const{
    	os << "Account type: Saving" << endl;
    	os << "Balance: $ " << fixed << setprecision(2) <<getBalance() << endl;
    	os << "Interest Rate (%): " << fixed << setprecision(2) << interestRate * 100.00 << endl;

    	return os;
    }
}
