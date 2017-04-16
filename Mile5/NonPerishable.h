#ifndef ICT_NONPERISHABLE_H__
#define ICT_NONPERISHABLE_H__
#include"Error.h"
#include"Item.h"

namespace ict{
   class NonPerishable : public Item{
      Error m_err;

   protected:
      bool ok() const;
      void error(const char * message);

      virtual char signature() const{
         return 'N';
      }

   public:
      std::fstream& save(std::fstream& file)const;
      std::fstream& load(std::fstream& file);
      ostream& write(ostream& ostr, bool linear)const;
      std::istream& read(std::istream& istr);

   };
}







#endif
