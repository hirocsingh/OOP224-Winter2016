#define _CRT_SECURE_NO_WARNINGS

#include"PosApp.h"

#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

namespace ict{

   //Private Member Functions--------------------------------------->
   int PosApp::menu(){
      cout.flush();
      int choice = -1;
      cout << "The Sene-Store" << endl;
      cout.flush();
      cout << "1- List items"  << endl;
      cout.flush();
      cout << "2- Add Perishable item" << endl;
      cout.flush();
      cout << "3- Add Non-Perishable item" << endl;
      cout.flush();
      cout << "4- Update item quantity" << endl;
      cout.flush();
      cout << "5- Show Item" << endl;
      cout.flush();
      cout << "6- POS" << endl;
      cout.flush();
      cout << "0- exit program" << endl;
      cout.flush();
      cout << "> ";
      cin >> choice;
      cin.ignore();
      if (cin.fail() || choice > 6 || choice < 0) {
         cin.clear();
         cin.ignore(2000, '\n');
         choice = -1;
      }
      return choice;
   }


   void PosApp::deallocateItems(){
      for( int i = 0; i < m_noOfItems; i++)
         delete m_items[i];
      m_noOfItems = 0;
   }

   void PosApp::loadRecs(){
      deallocateItems();
      fstream file;
      int i = 0 ;
      file.open(m_fielname,ios::in);
      if(file.fail()){
         file.clear();
         file.open(m_fielname,ios::out);
         file.close();
      }
      else{
         char ch;
         	while (!file.eof()){
               ch = file.get();
               if(ch == 'P'){
                  Perishable* item = new Perishable;
                  item->load(file);
                  m_items[i] = item;
                  i++;
                  ch = 0;
               }
               else if(ch == 'N'){
                  NonPerishable* N_item = new NonPerishable;
                  N_item->load(file);
                  m_items[i] = N_item;
                  i++;
                  ch = 0;
               }
            }
      }
      m_noOfItems = i;
      file.close();
   }

   // Didn't take any help, just followed the specification given in the Milestone Document.
   void PosApp::saveRecs(){
      fstream file;
      file.open(m_fielname,ios::out);
      int i = 0;
      for (i = 0; i < m_noOfItems; i++){
         if(m_items[i]->quantity() > 0)
            m_items[i]->save(file);
      }
      file.close();
      loadRecs();
   }

   // Didn't take any help, just followed the specification given in the Milestone Document.
   int PosApp::searchItems(const char* sku)const{
      int index = -1;
      for (int i = 0; i < m_noOfItems; i++){
         if (*m_items[i] == sku){
            index = i;
         }
      }
      return index;
   }

   // Didn't take any help, just followed the specification given in the Milestone Document.
   void PosApp::updateQty(){
      int search;
      int toUpdate;
      char sku[MAX_SKU_LEN];
      cout << endl << "Please enter he SKU: ";
      cin >> sku;
      cin.ignore();
      search = searchItems(sku);
      if(search == -1)
         cout << "Not found!" << endl;
      else{
         m_items[search]->write(cout,false);
         cout << endl << endl << "Please enter the number of purchased items: ";
         cin >> toUpdate;
         cin.ignore();
         *m_items[search] += toUpdate;
         saveRecs();
         cout << "Updated!" << endl << endl;
      }

   }

   // Didn't take any help, just followed the specification given in the Milestone Document.
   void PosApp::addItem(bool isPerishable){
      Item* tempItem;
      if (isPerishable){
         tempItem = new Perishable;
      }
      else{
         tempItem = new NonPerishable;
      }
      tempItem->read(cin);
      if (!cin.fail()){
         m_items[m_noOfItems] = tempItem;
         m_noOfItems++;
         saveRecs();
         cout << "Item added." << endl << endl;
      }
      else{
         cin.clear();
         tempItem->write(cout,false);
         cout << endl;
      }

   }

   // Didn't take any help, just followed the specification given in the Milestone Document.
   void PosApp::listItems()const{
      double total_asset = 0.0;
      cout << endl;
      cout << "Row  | SKU    | Item Name          | Price |TX |Qty | Total   |" << endl
           << "-----|--------|--------------------|-------|---|----|---------|" << endl;
      for(int i = 0; i < m_noOfItems; i++){
         cout << setw(4) << left << (i+1) << " | ";
         m_items[i]->write(cout, true) << endl;

         total_asset += m_items[i]->cost() * m_items[i]->quantity();
      }

      cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
      cout << "                              Total Assest: $  |" << setw(14) << fixed << setprecision(2) << right << total_asset << "|" << endl;
      cout << "-----------------------------------------------^--------------^" << endl << endl;
   }
   //End Private Member Functions----------------------------------->

   //Member Functions----------------------------------------------->

   // Didn't take any help, just followed the specification given in the Milestone Document.
   void PosApp::truncateBillFile(){
      fstream file;
      file.open(m_billfname,ios::out|ios::trunc);
      file.close();
   }

   void PosApp::showBill(){

	   //Taken this part of code which was already written in Date.cpp
	   //---------------------------------------------------------
	   time_t t = time(NULL);
	   tm lt = *localtime(&t);
	   int day = lt.tm_mday;
	   int mon = lt.tm_mon + 1;
	   int year = lt.tm_year + 1900;
	   int hour = lt.tm_hour;
	   int min = lt.tm_min;
	   //---------------------------------------------------------

        fstream file;
        file.open(m_billfname,ios::in);
        char ch;
        double total = 0.0;
        int i = 0;
        cout << "v--------------------------------------------------------v" << endl;
        cout << "|"<<year<<"/"<<mon<<"/"<<day<<", "<<hour<<":"<<min<<"                                        |" << endl;
        cout << "| SKU    | Item Name          | Price |TX |Qty | Total   |" << endl
             << "|--------|--------------------|-------|---|----|---------|" << endl;
        while (!file.eof()){
           //file.ignore();
           //delete m_items[i];
           ch = file.get();
           if(ch == 'P'){
        	   // // Didn't take any help, just followed the specification given in the Milestone Document.
              Perishable* newP = new Perishable;
              newP->load(file);
              //m_items[i] = newP;
              total += newP->cost() * newP->quantity();
              cout << "| ";
              newP->write(cout, true) << endl;
              delete newP;
              i++;
           }
           else if(ch == 'N'){

        	   // Didn't take any help, just followed the specification given in the Milestone Document.
              NonPerishable* newNP = new NonPerishable;
              newNP->load(file);
              //m_items[i] = newNP;
              total += newNP->cost() * newNP->quantity();
              cout << "| ";
              newNP->write(cout, true) << endl;
              delete newNP;
              i++;
           }
                 }
        cout  << "^--------^--------------------^-------^---^----^---------^" << endl
              << "|                               Total: $  |" << setw(14) << fixed << right << setprecision(2) << total << "|" << endl
              << "^-----------------------------------------^--------------^" << endl << endl;
        file.close();
        truncateBillFile();


     }


   // Didn't take any help, just followed the specification given in the Milestone Document.
   void PosApp::addToBill(Item& I){
      fstream file;
      int qty = I.quantity();
      I.quantity(1);

      file.open(m_billfname,ios::out|ios::app);
      if(file.fail()){
         file.open(m_billfname,ios::out|ios::app);
      }

      I.save(file);
      I.quantity(qty-1);
      file.close();
      saveRecs();
   }

   // Didn't take any help, just followed the specification given in the Milestone Document.
   void PosApp::POS(){

      string sku;
      char sku2[MAX_SKU_LEN];
      int index;
      cout << endl;
      cout << "Sku: ";
      // 1.This Particular loop I studied from stackoverflow.com.
      while(std::getline(cin, sku)){
    	  if(sku.empty()){
    		  break;
    	  }
    	  else{
    		  strcpy(sku2,sku.c_str());
    		  index = searchItems(sku2);
    		  if(index == -1){
    			  cout << "Not Found" << endl;
    			  //cin.ignore();
    		  }
    		  else{
    			  cout << "v------------------->" << endl;
    			  cout << "|" << right << m_items[index]->name() << endl;
    			  cout << "v------------------->" << endl;
    			  addToBill(*m_items[index]);

    		  }
    		  cout << "Sku: ";
    	  }
      }
      showBill();


   }
   //End Member Functions------------------------------------------->

   //Default Constructor-------------------------------------------->
   // Didn't take any help, just followed the specification given in the Milestone Document.
   PosApp::PosApp(const char* filename, const char* billfname){
      strcpy(m_billfname,billfname);
      strcpy(m_fielname,filename);
       m_noOfItems = 0;
      loadRecs();

   }

   //Only Public Function------------------------------------------->
   void PosApp::run(){

      char temp[MAX_SKU_LEN];
      int selection = menu();
      if(selection == -1){
         cout << "===Invalid Selection, try again.===\n" << endl;
         cout.flush();
         selection = menu();
      }
      int index = -1;
      while (selection != -1){
         switch (selection){
            case 0:
               cout << endl << "Goodbye!!" << endl << endl;
               cout.flush();
               selection = -1;
               break;
            case 1:
               listItems();
               selection = menu();
               break;
            case 2:
               addItem(true);
               selection = menu();
               break;
            case 3:
               addItem(false);
               selection = menu();
               break;
            case 4:
               updateQty();
               selection = menu();
               break;
            case 5:
               cout << endl << "Please enter the SKU: ";
               cin >> temp;
               index= searchItems(temp);
               if (index == -1){
                  cout << "Not found!" << endl;
               }
               else{
                  cout << "v-----------------------------------v" << endl;
                  m_items[index]->write(cout, false);
                  cout << endl << "^-----------------------------------^" << endl << endl;
               }
               selection = menu();
               break;
            case 6:
               POS();
               selection = menu();
               break;
            default:
               cout << "===Invalid Selection, try again.===\n" << endl;
               selection = menu();
               break;
         }
      }
   }

}

