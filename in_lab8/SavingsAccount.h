/* Name : Avinash Singh
 * OOP244 Section B
 * Workshop8
 * 20 - March - 2017
 */

#ifndef ICT_SAVINGSACCOUNT_H__
#define ICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class SavingsAccount : public Account{
		private:
    		double interestRate; // interest rate (percentage)
		public:

			// TODO: put prototypes here
    		SavingsAccount(double bal,double int_rate);

    		double calculateInterest();

    		std::ostream& display(std::ostream& os)const;

   };
};
#endif
