/* Name : Avinash Singh
 * OOP244 Section B
 * Workshop8
 * 20 - March - 2017
 */

#include "Account.h"

using namespace std;

namespace ict{

	// constructor
	Account::Account (double bal){
		if(bal >= 0)
			balance = bal;
		else
			balance = 1.0;
	}


	// credit (add) an amount to the account balance


	// debit (subtract) an amount from the account balance return bool


	double Account::getBalance() const
	{
		return balance;
	}

	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	}
}
