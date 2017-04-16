#ifndef ICT_PERISHABLE_H__
#define ICT_PERISHABLE_H__
#include"Date.h"
#include "NonPerishable.h"


namespace ict {
   class Perishable : public NonPerishable {
      Date m_expiry;

   protected:
      char signature() const;
   public:

      Perishable();

      std::fstream& save(std::fstream& file)const;
      std::fstream& load(std::fstream& file);
      ostream& write(ostream& ostr, bool linear)const;
      std::istream& read(std::istream& istr);


   };
}




#endif
