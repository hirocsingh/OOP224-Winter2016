#define _CRT_SECURE_NO_WARNINGS
// Lib includes
#include<iostream>
#include <cstring>
// inlcude Item and POS header files
#include "Item.h"
#include "POS.h"

using namespace std;
namespace ict{
// class Item implementaion
   void Item::sku(const char* csku)
   {
      if (csku){
         strncpy(m_sku, csku, MAX_SKU_LEN);
         m_sku[MAX_SKU_LEN] = 0;
      }
   }
   void Item::price(double value)
   {
      m_price = value;

   }
   void Item::name(const char* cname)
   {
      if (cname){
         unsigned long len = strlen(cname) + 1;
         m_name = new char[len];
         strcpy(m_name, cname);
      }
   }
   void Item::quantity(int value)
   {
      m_quantity = value;
   }
   void Item::taxed(bool value)
   {
      m_taxed = value;
   }


   Item::Item(){
      name(nullptr);
      sku(nullptr);
      taxed(false);
      quantity(0);
      price(0);
   }

   Item::Item(const char sku[], const char * name, double price, bool taxed){
      strncpy(m_sku,sku,MAX_SKU_LEN);
      if(name != nullptr){
         m_name = new char[strlen(name) + 1];
            strcpy(m_name,name);
      }
      m_quantity = 0;
      m_price = price;
      m_taxed = taxed;
   }

   Item::Item(const Item& other){
      m_quantity = other.m_quantity;
      m_price = other.m_price;
      m_taxed = other.m_taxed;
      if(other.m_sku[0] != '\0')
         strcpy(m_sku,other.m_sku);
      else
         sku(nullptr);

      if(other.m_name != nullptr){
         m_name = new char[strlen(other.m_name) + 1];
         strcpy(m_name,other.m_name);
      }
      else
         name(nullptr);


   }

   Item& Item::operator=(const Item& other){
      if(this != &other){
         m_quantity = other.m_quantity;
         m_price = other.m_price;
         m_taxed = other.m_taxed;

         if(other.m_sku[0] != '\0')
            strcpy(m_sku,other.m_sku);
         else
            sku(nullptr);

         if(other.m_name != nullptr){
            m_name = new char[strlen(other.m_name) + 1];
            strcpy(m_name,other.m_name);
         }
         else
            name(nullptr);
      }
      return *this;
   }

   const char* Item::name() const{
      return m_name;
   }
   const char* Item::sku() const{
      return m_sku;
   }
   double Item::price() const{
      return m_price;
   }
   bool Item::taxed() const{
      return m_taxed;
   }
   int Item::quantity() const{
      return m_quantity;
   }

   double Item::cost() const{
      double cost;
      if(m_taxed == true){
         cost = (m_price + ( m_price * TAX ));
      }
      else
         cost = m_price;
      return cost;

   }
   bool Item::isEmpty() const{
      return (m_name == nullptr && m_sku[0] == '\0' && m_price == 0 && m_quantity == 0 && m_taxed == false);
   }

   bool Item::operator==(const char *sku){
      return !strcmp(m_sku,sku);

   }
   int Item::operator-=(const int quantity){
      return m_quantity -= quantity;
   }
   int Item::operator+=(const int quantity){
      return m_quantity += quantity;
   }


   double operator+=(double& d, const Item& I){
      d += I.cost()*I.quantity();
      return d;
   }
   // operator << and operator >>
   std::ostream& operator<<(std::ostream& cout, const Item& D){
      return D.write(cout,true);
   }
   std::istream& operator>>(std::istream& cin, Item& D){
      return D.read(cin);
   }
}
