//
//  Item.h
//  OOP_Mileston3
//
//  Created by Avinash Singh on 17/03/17.
//  Copyright © 2017 Avinash Singh. All rights reserved.
//

#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__
// inlcude PosIO and POS header files
#include "POS.h"
#include "PosIO.h"

namespace ict{
   // class Item
   class Item : public PosIO{
   private:

      char m_sku[MAX_SKU_LEN + 1];
      char *m_name;
      double m_price;
      bool m_taxed;
      int m_quantity;

   public:
      Item();
      Item(const char sku[], const char * name, double price, bool taxed = true);
      Item(const Item& other);
      Item& operator=(const Item& other);

      virtual ~Item(){
         delete [] m_name;
         m_name = nullptr;
      }

      void sku(const char* csku);
      void price(double value);
      void name(const char* cname);
      void quantity(int value);
      void taxed(bool value);

      const char* name() const;
      const char* sku() const;
      double price() const;
      bool taxed() const;
      int quantity() const;

      double cost() const;
      bool isEmpty() const;

      bool operator==(const char *sku);
      int operator-=(const int quantity);
      int operator+=(const int quantity);

   };
   // end class Item
   // operator +=
   double operator+=(double& d, const Item& I);
   // operator << and operator >>
   std::ostream& operator<<(std::ostream& cout, const Item& D);
   std::istream& operator>>(std::istream& cin, Item& D);

}


#endif
