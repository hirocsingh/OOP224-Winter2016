#include<iostream>
#include"Contact.h"
#include<string>
 using namespace std;

 namespace communication{

 	 void Contact::set(){
 		m_name[0] = '\0';
 		m_phoneNumbers = nullptr;
 		m_noOfPhoneNumbers = 0;
 	 }

 	 bool Contact::isValid(long long phoneNo) const{
 		bool valid = false;
 		if(phoneNo >=11001000000 && phoneNo <= 999999999999){
 			valid = true;
 			}
 		return valid;
 	 }

 	 Contact::Contact(){
 		 set();
 	 }

 	 Contact::Contact(const char _name[],long long _phoneNumber[],int size){
 		int i,count=0;
 		set();
 		if(_name != nullptr){
 			 strncpy(m_name,_name,20);
 		}
 		m_name[20] = '\0';
 			 m_noOfPhoneNumbers = size;
 			 for(i=0;i<size;i++){
 				 if(isValid(_phoneNumber[i])){
 					 count++;
 				 }
 			 }
 			 if(_phoneNumber != nullptr){
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

 	 Contact::~Contact(){
 		 delete [] m_phoneNumbers;
 		 //m_phoneNumbers = nullptr;
 	 }

 	 bool Contact::isEmpty() const{
 		 return (m_name[0] == '\0' && m_phoneNumbers == nullptr && m_noOfPhoneNumbers == 0);
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
 }
