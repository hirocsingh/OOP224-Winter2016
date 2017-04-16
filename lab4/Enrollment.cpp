#include<iostream>
#include"Enrollment.h"
using namespace std;

namespace sict {
  
  //done
  bool Enrollment::isValid()const{
    return name_ && name_[0];
  }
  //done
  void Enrollment::setEmpty(){
    name_[0] = 0;
    code_[0] = 0;
    year_ = 0;
    semester_ = 0;
    slot_ = 0;
    enrolled_ = false;
  }
  // done
  bool Enrollment::isEnrolled() const{
    return enrolled_;
  }

  // done
  void Enrollment::display(bool nameOnly)const{
    if (isValid()){
      cout << name_;
      if (!nameOnly){
        cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
        cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
      }
    }
    else{
      cout << "Invalid enrollment!" << endl;
    }
  }

  void Enrollment::set(const char* name,const char* code,int year,int semester,int time, bool enrolled=false) {
	  if(isString(name))
	  strcpy(name_,name);
	  strcpy(code_,code);
	  year_=year;
	  semester_=semester;
	  slot_=time;
	  enrolled_=enrolled;
  }

  bool hasConflict(const Enrollment &other) const {
	  if(other.year_ == e1.year_)
		  return true;

  }
}



