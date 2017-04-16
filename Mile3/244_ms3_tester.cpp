// Final Project Milestone 3
// Item Tester program
// File	244_ms3_tester.cpp
// Version 1.0
// Date	3/17/2017
// Author	Fardad Soleimanloo
//
/////////////////////////////////////////////////////////////////

#include <iomanip>
#include "Item.h"
#define TAB '\t'
using namespace std;
namespace ict {
   class testItem :public Item {
   public:
      testItem() :Item("", "", 0, 0) {}
      testItem(const testItem& SG) :Item(SG) {};
      std::fstream& save(std::fstream& file)const {
         file.open("244_ms3.txt", ios::out);
         file << sku() << TAB << name() << TAB << quantity() << TAB
         << int(taxed()) << TAB << price() << endl;
         file.close();
         return file;
      }
      std::fstream& load(std::fstream& file) {
         file.open("244_ms3.txt", ios::in);
         char buf[2000];
         double dbuf;
         int ibuf;
         file >> buf;
         sku(buf);
         file >> buf;
         name(buf);
         file >> ibuf;
         quantity(ibuf);
         file >> ibuf;
         taxed(!!ibuf);
         file >> dbuf;
         price(dbuf);
         file.close();
         return file;
      }
      std::ostream& write(std::ostream& os, bool linear)const {
         return os << sku() << ": " << name() << endl
         << "Qty: " << quantity() << endl
         << "Cost:" << fixed << setprecision(2) << cost();
      }
      std::istream& read(std::istream& is) {
         char buf[2000];
         double dbuf;
         int ibuf;
         cout << "sku: ";
         is >> buf;
         sku(buf);
         is.ignore();
         cout << "name: ";
         is.getline(buf, 2000);
         name(buf);
         cout << "qty: ";
         is >> ibuf;
         quantity(ibuf);
         cout << "is taxed? (1/0): ";
         is >> ibuf;
         taxed(!!ibuf);
         cout << "price: ";
         is >> dbuf;
         price(dbuf);
         return is;
      }
   };
}

using namespace ict;
ostream& prnItem(ostream& ostr, const Item& I) {
   return ostr << "-------------------------" << endl << I << endl << "-------------------------";
}
int main() {
   double res, val = 0.0;
   fstream F;
   testItem I1, I2, I3;
   Item* Ip;
   int i, cnt, ret;
   cout << "Please enter the following informartion for Item:" << endl
   << "sku: 123<ENTER>" << endl
   << "name: abcd<ENTER>" << endl
   << "qty: 10<ENTER>" << endl
   << "is taxed? 1<ENTER>" << endl
   << "price 10.0<ENTER>" << endl;
   cout << "Enter Item info: " << endl;
   cin >> I1;
   cout << "You entered: " << endl;
   prnItem(cout, I1) << endl;
   cout << "Copying Item..." << endl;
   for (cnt = 1, i = 0; i < 10000000; i++) {
      Ip = new testItem(I1);
      if (i % 100000 == 0) {
         cout << "\r%" << cnt++;
      }
      if (i == 9999999) {
         cout << endl  << "Copied Item:" << endl;
         prnItem(cout, *Ip) << endl;
      }
      delete Ip;
   }
   cout << "Original Item:" << endl;
   prnItem(cout, I1) << endl;
   cout << "Saving I1 in file:" << endl;
   I1.save(F);
   cout << "Loading Saved item into I2:" << endl;
   I2.load(F);
   cout << "Printing Loaded item from file:" << endl;
   prnItem(cout, I2) << endl;
   cout << "Assigning Item to another..." << endl;
   for (cnt = 1, i = 0; i < 10000000; i++) {
      I3 = I1;
      if (i % 100000 == 0) {
         cout << "\r%" << cnt++;
      }
      if (i == 9999999) {
         cout << endl << "Assigned Item:" << endl;
         prnItem(cout, I3) << endl;
      }
   }
   cout << "Original Item:" << endl;
   prnItem(cout, I1) << endl;
   cout << "Testing operator==:" << endl;
   cout << "Operator==() is " << ((I1 == "123") ? "OK" : "NOT OK") << endl << endl;
   cout << "Testing operator+=  I1+= 20..." << endl;
   cout << "Original Item:" << endl;
   prnItem(cout, I1) << endl;
   ret = I1 += 20;
   cout << "After adding 20:" << endl;
   prnItem(cout, I1) << endl << "returned value: " << ret << endl;
   cout << "Testing operator-=  I1-= 20..." << endl;
   cout << "Original Item:" << endl;
   prnItem(cout, I1) << endl;
   ret = I1 -= 20;
   cout << "After deducting 20:" << endl;
   prnItem(cout, I1) << endl << "returned value: " << ret << endl;
   cout << "Setting I1 not to be taxed:" << endl;
   I1.taxed(false);
   cout << "Original Item but no tax:" << endl;
   prnItem(cout, I1) << endl;
   cout << "operator+=(double, Item):" << endl;
   res = val += I1;
   cout << res << "=" << val << endl << endl;
   return 0;
}
