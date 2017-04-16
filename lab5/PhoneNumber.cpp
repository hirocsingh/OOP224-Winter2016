// OOP244 Workshop 5: Classes with resources 
// File: PhoneNumber.cpp
// Version: 1.0
// Date: 2016/02/15
// Author: Fardad Soleimanloo
/////////////////////////////////////////////

#include "PhoneNumber.h"
#include <cstring>
#include <iostream>     
#include <iomanip>
using namespace std;
namespace sict {
	void PhoneNumber::setEmpty() {
		area_ = number_ = 0;
		type_ = nullptr;
	}

	bool PhoneNumber::isValid(int area, int number, const char* type)const {
		// "type_ && type_[0], same as: type_ != nullptr && type_[0] != '\0', which means, 
		//      first if type_ is not null and is pointing to something, 
		//      then if "something" is not an empty string and etc....
		// lazy evaluation
		return type && type[0] && area >= 111 && area <= 999 && number >= 1111111 && number <= 9999999;
	}

	bool PhoneNumber::allocateAndCopy(int area, int number, const char* type) {
		bool valid = isValid(area, number, type);
		if (valid) {
			area_ = area;
			number_ = number;
			// dynamic resource allocation: 
			delete[] type_; // if not null delete the target of type_ for new allocation 
			type_ = new char[strlen(type) + 1];
			strcpy(type_, type);
		}
		return valid;
	}


	PhoneNumber::PhoneNumber() {
		setEmpty();
	}


	PhoneNumber::PhoneNumber(const PhoneNumber& cp) {
		type_ = nullptr; // same as type_ = (char*)0, setting unused pointer to null so allocateAndCopy does not delete
						 // some random pointed memory causing segmentation fault. 
		if (!allocateAndCopy(cp.area_, cp.number_, cp.type_)) { // reusing logic
			setEmpty();
		}
	}
	PhoneNumber::~PhoneNumber() {
		delete[] type_;
	}
	PhoneNumber& PhoneNumber::operator=(const PhoneNumber& ro) {
		if (!allocateAndCopy(ro.area_, ro.number_, ro.type_)) {// reusing logic
			setEmpty();
		}
		return *this;
	}


	// Performs a fool-proof entry of phone number form console in following format:
	// Type 999 9999999
	void PhoneNumber::read() {
		bool bad = true;
		char type[16];
		int area;
		int number;
		while (bad) {
			cin.getline(type, 16, ',') >> area >> number;
			if (cin.fail()) {
				cin.clear();
				cout << "Incorrect format, retry please (NumberType, 999 999999): ";
			}
			else if (!allocateAndCopy(area, number, type)) {
				cout << "Invalid phone number!" << endl
					<< "Use this format: type, AAA NNNNNNN" << endl
					<< "type: maximum 15 chars (Home, Mobile, etc)" << endl
					<< "AAA: 111<=AAA<=999" << endl
					<< "NNNNNNN: 1111111<=NNNNNNN<=9999999" << endl
					<< "Retry: ";
			}
			else {
				bad = false;
			}
			cin.ignore(1000, '\n');
		}
	}


	void PhoneNumber::display(bool goToNewLine)const {
		if (!isEmpty()) {
			cout << setw(15) << left << setfill('.') << type_ << ", " << area_ << " " << number_ / 10000 << "-" << setw(4) << setfill('0') << number_ % 10000;
			if (goToNewLine) cout << endl;
		}
	}
	bool PhoneNumber::isEmpty()const {
		return type_ == nullptr;
	}
}
