

#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_
#include"PhoneNumber.h"
namespace sict {
	class Contact {
		char name_[41];
		PhoneNumber* phoneNumber_;
		int noPN_;
		void setEmpty();

	public:
		Contact();
		Contact(const char* name,int num){
			phoneNumber_ = new PhoneNumber[num];
			name_ = name;
			noPN_ = num;
		}
		~Contact();
		void read();		
		bool isEmpty()const;
		void display() const;
	};

}
#endif
