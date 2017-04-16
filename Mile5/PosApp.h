#ifndef ICT_POSAPP_H__
#define ICT_POSAPP_H__

#include"Item.h"
#include "Perishable.h"
#include "NonPerishable.h"

#include<iostream>

namespace ict {
   class PosApp {
      //DATA MEMBERS------------------------------------
      char m_fielname[128];
      char m_billfname[128];
      Item* m_items[MAX_NO_ITEMS];
      int m_noOfItems;

      //Private Member Functions------------------------
      int menu();
      void deallocateItems();
      void loadRecs();
      void saveRecs();
      int searchItems(const char* sku)const;
      void updateQty();
      void addItem(bool isPerishable);
      void listItems()const;

      //Point of sale Member functions------------------
      void truncateBillFile();
      void showBill();
      void addToBill(Item& I);
      void POS();

   public:
      //Copy Cinstruct & Assignment Operator------------
      PosApp(const PosApp& other);
      PosApp& operator=(const PosApp& other);


      PosApp(const char* filename, const char* billfname);
      void run();



   };
}

#endif
