/* Author : Avinash Singh
 * OOP244 Section B
 * ID : 115408163
 * Milestone 1
 * File : Date.cpp
 * Date : 2017 - March - 11
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
#include "POS.h"


namespace ict{

   //Private Functions=======================================
   void Date::set(){
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      m_day = lt.tm_mday;
      m_mon = lt.tm_mon + 1;
      m_year = lt.tm_year + 1900;
      if (dateOnly()){
         m_hour = m_min = 0;
      }
      else{
         m_hour = lt.tm_hour;
         m_min = lt.tm_min;
      }
   }

   int Date::value()const{
      return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
   }

   int Date::mdays()const{
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }

   void Date::errCode(int errorCode){
      m_readErrorCode = errorCode;
   }

   void Date::set(int year, int mon, int day, int hour, int min){
      m_year = year;
      m_mon = mon;
      m_day = day;
      m_hour = hour;
      m_min = min;
      m_readErrorCode = NO_ERROR;
   }

   //End Private Functions====================================

   //Constructors=============================================

   Date::Date(){
      m_dateOnly = false;
      set();
   }

   Date::Date(int year,int month,int day){
      m_dateOnly = true;
      m_year = year;
      m_mon = month;
      m_day = day;
      m_hour = m_min = 0;
      errCode(NO_ERROR);
   }

   Date::Date(int year,int month,int day,int hour,int min){
      m_dateOnly = false;
      m_year = year;
      m_mon = month;
      m_day = day;
      m_hour = hour;
      m_min = min;
      errCode(NO_ERROR);

   }

   //End Constructors=========================================

   //Getter Function==========================================

   int Date::errCode()const{
      return m_readErrorCode;
   }

   bool Date::bad()const{
      return m_readErrorCode != 0;
   }

   bool Date::dateOnly()const{
      return m_dateOnly;
   }

   void Date::dateOnly(bool value){
      m_dateOnly = value;
      if(value){
         m_hour = m_min = 0;
      }
   }
   //End Getter Functions=====================================

   //Operator Overloads=======================================

   bool Date::operator==(const Date& D)const{
      return this->value() == D.value();
   }

   bool Date::operator!=(const Date& D)const{
      return this->value() != D.value();
   }

   bool Date::operator<(const Date& D)const{
      return this->value() < D.value();
   }

   bool Date::operator>(const Date& D)const{
      return this->value() > D.value();
   }

   bool Date::operator<=(const Date& D)const{
      return this->value() <= D.value();
   }

   bool Date::operator>=(const Date& D)const{
      return this->value() >= D.value();
   }

   //End Operator Overloads===================================

   //IO member Functions======================================

   istream& Date::read(istream& is){
      char c;
      if(this->m_dateOnly){
         is >> m_year >> c >> m_mon >> c >> m_day;
         if(cin.fail())
            this->errCode(CIN_FAILED);
    	    else if(m_year < MIN_YEAR || m_year > MAX_YEAR)
    	        this->errCode(YEAR_ERROR);
          else if(m_mon < 1 || m_mon > 12)
    	        this->errCode(MON_ERROR);
          else {
             if(m_day <= 0 || m_day > mdays())
                this->errCode(DAY_ERROR);
             else
                this->errCode(NO_ERROR);
          }
      }

      else{
         is >> m_year >> c >> m_mon >> c >> m_day >> c >> m_hour >> c >> m_min;
         if(cin.fail())
            this->errCode(CIN_FAILED);
         else if(m_year < MIN_YEAR || m_year > MAX_YEAR)
            this->errCode(YEAR_ERROR);
         else if(m_mon < 1 || m_mon > 12)
            this->errCode(MON_ERROR);
         else if(m_day < 0 || m_day > mdays())
            this->errCode(DAY_ERROR);
         else if(m_hour < 0 || m_hour > 23)
            this->errCode(HOUR_ERROR);
         else {
            if(m_min < 0 || m_min > 59)
               this->errCode(MIN_ERROR);
         }
      }
      return is;
   }



   ostream& Date::write(ostream& ostr)const{
      if(m_dateOnly){
         ostr << m_year << "/" << setw(2) << setfill('0') << m_mon << "/" <<  setw(2) << setfill('0') << m_day << setfill(' ');
      }
      else{
         setw(17);
         ostr << m_year << "/" << m_mon << "/" << m_day << "," << m_hour << ":" << m_min ;
      }
      return ostr;
   }

   //End IO member Functions==================================

   //Helper Functions=========================================

   ostream& operator<<(ostream& cout, const Date& D){
      return D.write(cout);
   }

   istream& operator>>(istream& cin, Date& D){
      return D.read(cin);
   }

   //End Helper Functions=====================================


}
