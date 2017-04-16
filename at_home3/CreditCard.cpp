/* Name : Avinash Singh
 * Date : 30-Jan-2017
 * file :CreditCard.cpp
 */
#include<iostream>
#include<string>
#include"CreditCard.h"

using namespace std;
namespace sict {
		void CreditCard::name(const char cardHolderName[]) {
			strcpy(m_cardHolderName,cardHolderName);
		}

		void CreditCard::initialize(unsigned long long creditCardNumber,int instcode,int expiryYear,int expiryMonth,int numberInTheBack) {

					m_cardnumber = creditCardNumber;
					m_institutionCode = instcode;
					m_expiryYear = expiryYear;
					m_expiryMonth = expiryMonth;
					m_numberInTheback = numberInTheBack;
		}

		void CreditCard::write(bool displayName,bool displayCardInfo) const {
			if(isValid()){
				if(displayName == true && displayCardInfo == false)
					writeName();
				else if(displayName == false && displayCardInfo == false){}

			}
		}
		void CreditCard::write() const{
			if(isValid())
			{
				writeName();
				writeCardInfo();
			}
		}
		void CreditCard::write(bool displayCardInfo) const{
			if(isValid()){
				if(displayCardInfo == false)
					writeCardInfo();
			}
		}

		bool CreditCard::isValid() const {
			bool flag = false;
			if(m_cardHolderName[0] != '\0')
			{
				if(m_cardnumber >= MIN_CARD_NUMBER && m_cardnumber <= MAX_CARD_NUMBER){
						if(m_institutionCode >= MIN_INST_NUMBER && m_institutionCode <= MAX_INST_NUMBER) {
							if(m_expiryYear >= MIN_EXP_YEAR && m_expiryYear <= MAX_EXP_YEAR){
								if(m_expiryMonth >= 1 && m_expiryMonth <= 12){
									if(m_numberInTheback > 0 && m_numberInTheback < 1000){
										flag = true;
										}
									}
								}
							}
						}
			}
			return flag;
		}
		void CreditCard::writeName() const {
			cout <<"Cardholder: " << m_cardHolderName<<endl;
		}

		void CreditCard::writeCardInfo() const{
			cout <<"Card Number: " << m_cardnumber<<endl;
			cout <<"Institution: " << m_institutionCode<<endl;
			cout <<"Expires: " << m_expiryMonth << "/" << m_expiryYear<<endl;
			cout <<"Number at the back: " << m_numberInTheback;
		}



}
