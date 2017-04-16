#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__
/* Name : Avinash Singh
 * OOP244 Section B
 * Workshop8
 * 20 - March - 2017
 */

#include <iostream>

using namespace std;

namespace ict{

	class Account{
		private:
			double balance; // data member that stores the balance

		protected:
			double getBalance() const; // return the account balance
			void setBalance( double ); // sets the account balance

   		public:
			// TODO: Write a prototype for constructor which initializes balance
			Account(double bal);

			// TODDO: Write a function prototype for the virtual function credit
			virtual double credit(double credit){
				return (credit >= 0 ? balance += credit : balance);
			}

			// TODO: Write a function prototype for the virtual function debit
			virtual bool debit(double debit){
				bool deb = false;
				if(debit <= balance){
					balance -= debit;
					deb = true;
				}
				else
					deb = false;
				return deb;
			}

			// TODO: Write a function prototype for the virtual function display
			virtual std::ostream& display(std::ostream& os)const = 0;
   };
};
#endif
