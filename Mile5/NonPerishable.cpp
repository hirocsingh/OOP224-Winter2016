#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include "NonPerishable.h"
#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

namespace ict{
   bool NonPerishable::ok() const{
      return m_err.isClear();
   }

   void NonPerishable::error(const char * message){
      if(message != nullptr)
         m_err.message(message);
   }


   // 2. Got the reference from stackoverflow.com on how to write to file
   std::fstream& NonPerishable::save(std::fstream& file)const{
	char sign = signature();
      file << sign << "," << sku() << "," << name() << "," << price() << "," << taxed() << "," << quantity() << ((sign=='N')?"\n":"");
      return file;
   }

   // 3. Got the reference from stackoverflow.com on how to read from file
   std::fstream& NonPerishable::load(std::fstream& file){
         char sign = signature();
         char buff[144];
         file.ignore(1, ',');
         file.getline(buff, 144, ',');
         sku(buff);
         file.getline(buff, 144, ',');
         name(buff);
         file.getline(buff, 144, ',');
         price(atof(buff));
         file.getline(buff, 144, ',');
         taxed(bool(atoi(buff)));
         if(sign == 'P'){
            file.getline(buff, 144, ',');
            quantity(atoi(buff));
         }
         else {
            file.getline(buff, 144, '\n');
            quantity(atoi(buff));
         }


         return file;
      }

   ostream& NonPerishable::write(ostream& ostr, bool linear)const{
      if (!ok()){
         ostr << m_err.operator const char*();
      }
      else{
         if (linear){
            char sign = signature();
            ostr << setw(MAX_SKU_LEN) << left << sku() << "|"
            << setw(20) <<left << name() << "|"
            << setw(7) << right << setprecision(2) << fixed << price() << "|" ;

            if(taxed() && sign == 'N')
               ostr << setw(3) << right << "TN" << "|";
            else if( taxed() && sign == 'P')
               ostr << setw(3) << right << "TP" << "|";
            else if(!taxed() && sign == 'N')
               ostr << setw(3) << right << "N" << "|";
            else
               ostr << setw(3) << right << "P" << "|";

            ostr << setw(4) << right << quantity() << "|"
            << setw(9) << right << setprecision(2) << fixed << cost() * quantity() << "|" ;
         }
         else{
            ostr << "Name: " << endl << name() << endl
            << "Sku: " << sku() << endl
            << "Price: " << price() << endl;
            if (taxed()){
               ostr << "Price after tax: " << cost() << endl;
            }
            else{
               ostr << "Price after tax: N/A" << endl;
            }
            ostr	<< "Quantity " << quantity() << endl
            << "Total Cost: " << cost() * quantity();
         }
      }

      return ostr;
   }
   std::istream& NonPerishable::read(std::istream& istr){
      m_err.clear();
      char buff[128];
      int buffInt = 0;
      double buffDob;
      char sign = signature();
      if(sign=='N')
         cout << endl << "Item Entry:" << endl;
      else
         cout << endl << "Perishable Item Entry:" << endl;

      cout << "Sku: " ;
      istr >> buff;
      if(!istr.fail())
         sku(buff);

      cout << "Name: " << endl;
      istr >> buff;
      if(!istr.fail())
         name(buff);

      cout << "Price: " ;
      istr >> buffDob ;
      if (!istr.fail()){
         price(buffDob);
         cout << "Taxed: " ;
         istr >> buff;
         if (buff[0] == 'Y' || buff[0] == 'y' ||
             buff[0] == 'N' || buff[0] == 'n'){
         istr.clear();
         if (buff[0] == 'Y' || buff[0] == 'y'){
            taxed(true);
         }
         else{
            taxed(false);
         }
            cout << "Quantity: " ;
            istr >> buffInt;
            if (!istr.fail()){
               quantity(buffInt);
            }
            else{
               m_err = "Invalid Quantity Entry";
               istr.setstate(ios::failbit);
            }
         }
         else{
            m_err = "Invalid Taxed Entry, (y)es or (n)o";
            istr.setstate(ios::failbit);
         }
      }
      else{

         m_err = "Invalid Price Entry";
         istr.setstate(ios::failbit);

      }
      return istr;

   }

}
