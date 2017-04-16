#define _CRT_SECURE_NO_WARNINGS
// lib includes




#include <iostream>
#include <fstream>
#include "Perishable.h"
using namespace std;


namespace ict{
   char Perishable::signature() const{
      return 'P';
   }

   Perishable::Perishable()
   {
      m_expiry.dateOnly(true);
   }



   fstream& Perishable::save(fstream& file)const
   {
      NonPerishable::save(file) << ",";
      m_expiry.write(file);
      return file;
   }
   fstream& Perishable::load(fstream& file)
   {
      NonPerishable::load(file);
      m_expiry.read(file);
      file.ignore(1);

      return file;
   }
   ostream& Perishable::write(ostream& os, bool linear)const
   {
      NonPerishable::write(os, linear);
      if (ok() && linear==false){
            os << endl << "Expiry date: ";
            m_expiry.write(os);

      }

      return os;
   }
   istream& Perishable::read(istream& is)
   {
      NonPerishable::read(is);
      if (ok()){
         cout << "Expiry date (YYYY/MM/DD): ";
         m_expiry.read(is);
      }

      switch (m_expiry.errCode()){
         case CIN_FAILED :
            error("Invalid Date Entry");
            is.setstate(ios::failbit);
            break;
         case YEAR_ERROR:
            error("Invalid Year in Date Entry");
            is.setstate(ios::failbit);
            break;
         case MON_ERROR:
            error("Invalid Month in Date Entry");
            is.setstate(ios::failbit);
            break;
         case DAY_ERROR:
            error("Invalid Day in Date Entry");
            is.setstate(ios::failbit);
            break;
      }
      return is;
   }
}
