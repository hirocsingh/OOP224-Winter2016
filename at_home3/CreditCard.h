/* Name : Avinash Singh
 * Date : 30-Jan-2017
 * file: CreditCard.h
 */
#ifndef SICT_CREDITCARD_H_
#define SICT_CREDITCARD_H_

#define MAX_NAME_LENGHT 40
#define MIN_INST_NUMBER 100
#define MAX_INST_NUMBER 999
#define MIN_EXP_YEAR 2017
#define MAX_EXP_YEAR 2037
#define MIN_CARD_NUMBER 4000000000000000
#define MAX_CARD_NUMBER 4000999999999999

namespace sict {

	class CreditCard {
	private:
		char m_cardHolderName[MAX_NAME_LENGHT];
		unsigned long long m_cardnumber;
		int m_institutionCode;
		int m_expiryYear;
		int m_expiryMonth;
		int m_numberInTheback;
		void writeName() const;
		void writeCardInfo() const;
	public:
		void name(const char cardholderName[]);
		void initialize(unsigned long long creditCardNumber,int instcode,int expiryYear,int expirymonth,int numberInTheBack);
		void write(bool,bool) const;
		void write() const;
		void write(bool) const;
		bool isValid() const;

	};
}

#endif
