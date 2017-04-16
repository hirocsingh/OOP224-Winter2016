/* Author : Avinash Singh
 * OOP244 Section B
 * ID : 115408163
 * Milestone 1
 * File : Date.h
 * Date : 2017 - March - 11
 */

// compilation safegaurds
#ifndef ICT_DATE_H_
#define ICT_DATE_H_
#include <iostream>

// ict namespace
namespace ict {
   // Date defined Error values
    #define NO_ERROR 0 //-- No error - the date is valid
    #define CIN_FAILED 1 //-- istream failed on accepting information using cin
    #define YEAR_ERROR 2 //-- Year value is invalid
    #define MON_ERROR 3 //-- Month value is invalid
    #define DAY_ERROR 4 //-- Day value is invalid
    #define HOUR_ERROR 5 //-- Hour value is invalid
    #define MIN_ERROR 6 //-- Minute value is invalid




   class Date {
   private:
      // member variables
       int m_year;
       //Year; a four digit integer between MIN_YEAR and MAX_YEAR, as defined in “POS.h”
       int m_mon;
       //Month of the year, between 1 to 12
       int m_day;
       //Day of the month, note that in a leap year February has 29 days, (see mday() member function)
       int m_hour;
       //A two digit integer between 0 and 23 for the hour the a day.
       int m_min;
       //A two digit integer between 0 and 59 for the minutes passed the hour
       int m_readErrorCode;
       bool m_dateOnly;


     // private methods
      int value()const;
      void set();
      int mdays()const;
      void errCode(int errorCode);
      //Sets the m_readErrorCode member variable to one of the possible values listed above.
      void set(int year, int mon, int day, int hour, int min);
      //Sets the member variables to the corresponding arguments and then sets the
      //m_readErrorCode to NO_ERROR.


   public:
      // constructors
       Date();
       Date(int year,int month,int day);
       Date(int year,int month,int day,int hour,int min = 0);



      // operator ovrloads
       bool operator==(const Date& D)const;
       bool operator!=(const Date& D)const;
       bool operator<(const Date& D)const;
       bool operator>(const Date& D)const;
       bool operator<=(const Date& D)const;
       bool operator>=(const Date& D)const;

      // methods
       int errCode()const;
       //Returns the m_readErrorCode value.
       bool bad()const;
       //Returns true if m_readErrorCode is not equal to zero.
       bool dateOnly()const;
       //Returns the m_dateOnly attribute.
       void dateOnly(bool value);
       //Sets the m_dateOnly attribute to the “value” argument. Also if the “value” is true, then
       //it will set m_hour and m_min to zero.




      // istream  and ostream read and write methods
       std::istream& read(std::istream& is = std::cin);
       std::ostream& write(std::ostream& ostr = std::cout)const;


   };
   // operator<< and >> overload prototypes for cout and cin
    std::ostream& operator<<(std::ostream& cout, const Date& D);
    std::istream& operator>>(std::istream& cin, Date& D);

}

#endif
