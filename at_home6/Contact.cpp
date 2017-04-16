#include<iostream>
#include"Contact.h"
#include<string>
 using namespace std;

 namespace communication{

 	 void Contact::set(){
 		m_name[0] = '\0';
 		m_phoneNumbers = nullptr;
 		m_noOfPhoneNumbers = 0;
 		m_index=0;
 	 }
 	bool Contact::isValid(long long phoneNo) const{
 	 		return phoneNo >=11001000000 && phoneNo <= 999999999999;

 	 }


 	 Contact::Contact(){
 	 		 set();
 	 	 }

 	Contact::~Contact(){
 	 		 delete [] m_phoneNumbers;
 	 		 //m_phoneNumbers = nullptr;
 	 	 }

 	Contact::Contact(const Contact &other){
 		m_index=0;
 		m_noOfPhoneNumbers= other.m_noOfPhoneNumbers;

 		strcpy(m_name,other.m_name);


 		if(other.m_phoneNumbers != nullptr){
 			m_phoneNumbers = new long long[m_noOfPhoneNumbers];
 			for(int i=0;i<m_noOfPhoneNumbers;i++)
 				m_phoneNumbers[i] = other.m_phoneNumbers[i];
 		}
 		else
 			m_phoneNumbers = nullptr;

 	}

 	Contact& Contact::operator=(const Contact& other){
 		//cout << "i created"<<endl;
 		if(this != &other){
 					m_noOfPhoneNumbers= other.m_noOfPhoneNumbers;

 			 			strcpy(m_name,other.m_name);


 			 		if(other.m_phoneNumbers != nullptr){
 			 			m_phoneNumbers = new long long[m_noOfPhoneNumbers];
 			 			for(int i=0;i<m_noOfPhoneNumbers;i++)
 			 				m_phoneNumbers[i] = other.m_phoneNumbers[i];
 			 		}
 			 		else
 			 			m_phoneNumbers = nullptr;
 		}
 		return *this;
 	}



 	Contact::Contact(const char _name[],long long _phoneNumber[],int size){
 			m_index=0;
 	 		int i,count=0;
 	 		//set();
 	 		//cout << "i created"<<endl;
 	 		if(_name != nullptr){
 	 			 strcpy(m_name,_name);
 	 		}
 	 		m_name[20] = '\0';
 	 			 m_noOfPhoneNumbers = size;
 	 			 //cout << m_noOfPhoneNumbers;
 	 			if(_phoneNumber != nullptr){
 	 			 for(i=0;i<size;i++){
 	 				 if(isValid(_phoneNumber[i])){
 	 					 count++;
 	 				 }
 	 			 }

 	 			 m_phoneNumbers = new long long[count];
 	 			 for(i=0;i<size;i++){
 	 				if(isValid(_phoneNumber[i])){
 	 				 		m_phoneNumbers[i] = _phoneNumber[i];
 	 				}
 	 				 }
 	 			 }
 	 			 else
 	 				 m_phoneNumbers = nullptr;
 	 	 }


 	void Contact::addPhoneNumber(const long long phoneNumber)
 	    {

 	        if(m_phoneNumbers == nullptr)
 	        {
 	            m_phoneNumbers = new long long[4];
 	        }
 	        if(isValid(phoneNumber))
 	        {
 	            m_phoneNumbers[m_index] = phoneNumber;
 	            m_index++;
 	            m_noOfPhoneNumbers++;
 	        }
 	    }

 	void Contact::display() const{

 	 		int i;
 	 		long long country,area,number1,number2;
 	 		if(isEmpty())
 	 			cout << "Empty contact!" << endl;
 	 		else{
 	 			cout << m_name << endl;
 	 			for(i=0; i< m_noOfPhoneNumbers; i++){
 	 					if(isValid(m_phoneNumbers[i])){
 	 			 			country = m_phoneNumbers[i] / 10000000000;
 	 			 			area = (m_phoneNumbers[i] % 10000000000) / 10000000;
 	 			 			number1 = (m_phoneNumbers[i] % 10000000) / 10000;
 	 			 			number2 = (m_phoneNumbers[i] % 10000000) % 10000;
 	 			 			cout << "(+" << country << ") " << area << " " << number1 << "-" << number2 << endl;
 	 			 			country = area = number1= number2 = 0;
 	 					}

 	 			}
 	 		}
 	 	 }

 	 bool Contact::isEmpty() const{
 	 		 return (m_name[0] == '\0' && m_phoneNumbers == nullptr && m_noOfPhoneNumbers == 0);
 	 	 }


 }


