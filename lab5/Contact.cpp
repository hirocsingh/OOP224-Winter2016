
#include"Contact.h"
using namespace std;
namespace sict{

  void Contact::read(){
    cout << "Contact Name: ";
    cin.getline(name_, 41, '\n');
    cout << "Please enter " << noPN_ << " phone numbers: " << endl;
    for (int i = 0; i < noPN_; i++){
      cout << i + 1 << ": ";
      phoneNumber_[i].read();
    }
  }

  bool Contact::isEmpty()const{
    return phoneNumber_ == nullptr;
  }

  void Contact::setEmpty(){
    name_[0] = 0;
    noPN_ = 0;
    phoneNumber_ = nullptr;
  }

  void Contact::display() const {

  }


}

/*Empty Contact
----------------------------------------
Enter Contact information:
Contact Name: John Doe
Please enter 3 phone numbers:
1: Home, 123 1234567
2: Cell, 234 2345678
3: Work, 345 3456789
John Doe
Home..........., 123 123-4567
Cell..........., 234 234-5678
Work..........., 345 345-6789
----------------------------------------
0:
Testing the contact with a looooong name
----------------------------------------
100000:
Testing the contact with a looooong name
----------------------------------------
200000:
Testing the contact with a looooong name
----------------------------------------
300000:
Testing the contact with a looooong name
----------------------------------------
400000:
Testing the contact with a looooong name
----------------------------------------
500000:
Testing the contact with a looooong name
----------------------------------------
600000:
Testing the contact with a looooong name
----------------------------------------
700000:
Testing the contact with a looooong name
----------------------------------------
800000:
Testing the contact with a looooong name
----------------------------------------
900000:
Testing the contact with a looooong name*/
