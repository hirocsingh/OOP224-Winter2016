// Final Project Milestone 1 All tests
// Version 1.0
// Date	2017/03/07
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of milestone 1
// for submission.
//
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Date.h"
#include "POS.h"
#include "Error.h"
using namespace std;
using namespace ict;

bool DefValTester_test1();
bool ConstructorTester_test2();
bool LogicalOperator_test3();
bool ErrorHandling_test4();
bool ErrorTester_test5();
int main() {
   bool ok = true;
   int i = 0;
   // uncomment the tests you would like to do

   ok = ok && DefValTester_test1() && (i += 1) && cout << "##################"<< endl;
   ok = ok && ConstructorTester_test2() && (i += 1)  && cout << "##################"<< endl;
   ok = ok && LogicalOperator_test3() && (i += 1)  && cout << "##################"<< endl;
   ok = ok && ErrorHandling_test4() && (i += 1)  && cout << "##################"<< endl;
   ok = ok && ErrorTester_test5() && (i += 1)  && cout << "##################"<< endl;


   if (ok ) {
      if (i == 5) {
         cout << "All tests passed, you may submit milestone 1";
      }
      else {
         cout << i << " test" << (i!=1?"s":"") << " out of 5 passed";
      }
      cout << endl;
   }
   return 0;
}


/* Test 1   Test 1   Test 1   Test 1   Test 1   Test 1   Test 1   Test 1   Test 1   */
bool DefValTester_test1() {
   bool ok = true;
   if (ok) {
      cout << "Checking defined values, POS.h: " << endl;
   }
   if (ok && MIN_YEAR != 2000) {
      cout << "MIN_YEAR must be 2000" << endl;
      ok = false;
   }
   if (ok && MAX_YEAR != 2030) {
      cout << "MAX_YEAR must be 2030" << endl;
      ok = false;
   }
   if (ok && (TAX - 0.13 > 0.0001 || TAX - 0.13 < -0.0001)) {
      cout << "TAX must be 0.13" << endl;
      ok = false;
   }
   if (ok && MAX_SKU_LEN != 7) {
      cout << "MAX_SKU_LEN must be 7" << endl;
      ok = false;
   }
   if (ok && MAX_NO_ITEMS != 2000) {
      cout << "MAX_NO_ITESM must be 2000" << endl;
      ok = false;
   }
   if (ok) {
      cout << "Passed!" << endl;
      cout << "Checking define values for error code in Data.h" << endl;
   }
   if (ok && NO_ERROR != 0) {
      cout << "NO_ERROR must be 0" << endl;
      ok = false;
   }
   if (ok && CIN_FAILED != 1) {
      cout << "CIN_FAILED must be 1" << endl;
      ok = false;
   }
   if (ok && YEAR_ERROR != 2) {
      cout << "YEAR_ERROR must be 2" << endl;
      ok = false;
   }
   if (ok && MON_ERROR != 3) {
      cout << "MON_ERROR must be 3" << endl;
      ok = false;
   }
   if (ok && DAY_ERROR != 4) {
      cout << "DAY_ERROR must be 4" << endl;
      ok = false;
   }
   if (ok && HOUR_ERROR != 5) {
      cout << "HOUR_ERROR must be 4" << endl;
      ok = false;
   }
   if (ok && MIN_ERROR != 6) {
      cout << "MIN_ERROR must be 6" << endl;
      ok = false;
   }
   if (ok) {
      cout << "Passed!" << endl;
   }
   if (ok) {
      cout << "Checking defined values passed, now run test no 2!" << endl;
   }
   else {
      cout << "You did not pass all the tests, keep working on your project!" << endl;
   }
   return ok;
}

/* Test 2  Test 2  Test 2  Test 2  Test 2  Test 2  Test 2  Test 2  Test 2  Test 2  Test 2  Test 2        */

bool equalDates(const Date& A, const Date& B);
bool yes();

bool ConstructorTester_test2() {
   bool ok = true;
   if (ok) {
      cout << "Testing Date constructors and operator<< overload; " << endl;
      time_t t = time(NULL);
      Date Cur;
      tm lt = *localtime(&t);
      Date tCur(lt.tm_year + 1900, lt.tm_mon + 1, lt.tm_mday, lt.tm_hour, lt.tm_min);
      cout << tCur << (equalDates(tCur, Cur) ? " is the same as " : " is not the same as ") << Cur << endl;

      if (equalDates(tCur, Cur)) {
         cout << "Passed!" << endl;
      }
      else {
         cout << "One or more of the Date constructors or operator<< are not implemented correctly." << endl;
         ok = false;
      }
   }
   if (ok) {
      Date A(2018, 10, 18);
      Date B = A;
      cout << "Testing Date(int, int, int) constructor and operator>> overload; " << endl;
      cout << "enter the following date, 2018/10/18" << endl << ">";
      cin >> B;

      if (!equalDates(A, B)) {
         cout << "Either the constructor or operator>> is not implemented correctly." << endl;
         ok = false;
      }
      else {
         cout << "Passed!" << endl;
      }
   }
   if (ok) {
      Date A(2015, 9, 7, 14, 30);
      Date B = A;
      B.dateOnly(false);
      cout << "Testing Date(int, int, int,int,int) constructor and operator>> overload; " << endl;
      cout << "enter the following date, 2015/9/7, 14:30" << endl << ">";
      cin >> B;

      if (!equalDates(A, B)) {
         cout << "Either the constructor or operator>> is not implemented correctly." << endl;
         ok = false;
      }
      else {
         cout << "Passed!" << endl;
      }
   }
   if (ok) {
      Date A(2015, 9, 7, 15);
      Date B = A;
      B.dateOnly(false);
      cout << "Testing Date(int, int, int,int,int=0) constructor and operator>> overload; " << endl;
      cout << "enter the following date, 2015/9/7, 15:0" << endl << ">";
      cin >> B;

      if (!equalDates(A, B)) {
         cout << "Either the constructor or operator>> is not implemented correctly." << endl;
         ok = false;
      }
      else {
         cout << "Passed!" << endl;
      }
   }
   if (ok) {
      cout << "You passed all Constructor tests, run test no 3!" << endl;
   }
   else {
      cout << "You did not pass all the tests, keep working on your project!" << endl;
   }
   return ok;
}
bool equalDates(const Date& A, const Date& B) {
   ostringstream Astr, Bstr;
   Astr << A;
   Bstr << B;
   return (Astr.str() == Bstr.str());
}

bool yes() {
   char ch;
   ch = cin.get();
   cin.ignore(1000, '\n');
   return ch == 'y' || ch == 'Y';
}


/* Test 3  Test 3  Test 3  Test 3  Test 3  Test 3  Test 3  Test 3  Test 3  Test 3  Test 3  Test 3  Test 3  Test 3  */

bool LogicalOperator_test3() {
   bool ok = true;
   if (ok) {
      cout << "Testing the logical operators: " << endl;
   }
   if (ok) {
      Date A(2018, 10, 18, 15);
      Date B(2018, 10, 18, 15);
      cout << "testing operator==" << endl;
      if (A == B) {
         cout << "passed!" << endl;
      }
      else {
         cout << A << " is equal to " << B << " but operator== returns otherwise!" << endl;
         ok = false;
      }
   }

   if (ok) {
      Date A(2018, 10, 18, 15);
      Date B(2018, 10, 18, 15);
      cout << "testing operator>=" << endl;
      if (A >= B) {
         cout << "passed!" << endl;
      }
      else {
         cout << A << " is equal to " << B << endl << "but operator>= returns otherwise!" << endl;
         ok = false;
      }
   }

   if (ok) {
      Date A(2018, 10, 18, 15);
      Date B(2018, 10, 18, 15);
      cout << "testing operator<=" << endl;
      if (A <= B) {
         cout << "passed!" << endl;
      }
      else {
         cout << A << " is equal to " << B << endl << "but operator<= returns otherwise!" << endl;
         ok = false;
      }
   }

   if (ok) {
      Date A(2018, 10, 17);
      Date B(2018, 10, 18, 15);
      cout << "testing operator!=" << endl;
      if (A != B) {
         cout << "passed!" << endl;
      }
      else {
         cout << A << " is not equal to " << B << " but operator!= returns otherwise!" << endl;
         ok = false;
      }
   }
   if (ok) {
      Date A(2018, 10, 17);
      Date B(2018, 10, 18, 15);
      cout << "testing operator<" << endl;
      if (A < B) {
         cout << "passed!" << endl;
      }
      else {
         cout << A << " is less than " << B << " but operator< returns otherwise!" << endl;
         ok = false;
      }
   }
   if (ok) {
      Date A(2018, 10, 17);
      Date B(2018, 10, 18, 15);
      cout << "testing operator>" << endl;
      if (B > A) {
         cout << "passed!" << endl;
      }
      else {
         cout << B << " is greater than " << B << " but operator> returns otherwise!" << endl;
         ok = false;
      }
   }
   if (ok) {
      Date A(2018, 10, 17);
      Date B(2018, 10, 18, 15);
      cout << "testing operator<=" << endl;
      if (A < B) {
         cout << "passed!" << endl;
      }
      else {
         cout << A << " is less than " << B << " but operator<= returns otherwise!" << endl;
         ok = false;
      }
   }
   if (ok) {
      Date A(2018, 10, 17);
      Date B(2018, 10, 18, 15);
      cout << "testing operator>=" << endl;
      if (B >= A) {
         cout << "passed!" << endl;
      }
      else {
         cout << B << " is greater than " << B << " but operator>= returns otherwise!" << endl;
         ok = false;
      }
   }
   if (ok) {
      cout << "You passed logical operator tests, now run test no 4!" << endl;
   }
   else {
      cout << "You did not pass all the tests, keep working on your project!" << endl;
   }
   return ok;
}

bool ErrorHandling_test4() {

   bool ok = true;

   if (ok) {
      Date A;
      A.dateOnly(true);
      cout << "Testing error handling in read funciton;" << endl;
      cout << "cin faliure detection, " << endl;
      cout << "Please enter the following string \"abcd\": ";
      cin >> A;
      if (A.errCode() == CIN_FAILED) {
         cout << "passed!" << endl;
      }
      else {
         cout << "Your read function does not check cin.fail() after entry," << endl
            << "or it did not set _readErrorCode to CIN_FAILED" << endl;
         ok = false;
      }
      cin.clear();
      cin.ignore(2000, '\n');
   }
   if (ok) {
      Date A;
      A.dateOnly(true);
      cout << "Year validation, " << endl;
      cout << "Please enter the following string \"10/1/1\": ";
      cin >> A;
      cout << "You entered: " << A << endl;
      if (A.errCode() == YEAR_ERROR) {
         cout << "passed!" << endl;
      }
      else {
         cout << "Your read function does not check the year entry limits after entry," << endl
            << "or it did not set _readErrorCode to YEAR_ERROR" << endl;
         ok = false;
      }
      cin.ignore(2000, '\n');
   }
   if (ok) {
      Date A;
      A.dateOnly(true);
      cout << "Month validation, " << endl;
      cout << "Please enter the following string \"2000/13/1\": ";
      cin >> A;
      cout << "You entered: " << A << endl;
      if (A.errCode() == MON_ERROR) {
         cout << "Passed" << endl;
      }
      else {
         cout << "Your read function does not check the month entry limits after entry," << endl
            << "or it did not set _readErrorCode to MON_ERROR" << endl;
         ok = false;
      }
      cin.ignore(2000, '\n');
   }
   if (ok) {
      Date A;
      A.dateOnly(true);
      cout << "Day validation, " << endl;
      cout << "Please enter the following string \"2000/1/50\": ";
      cin >> A;
      cout << "You entered: " << A << endl;
      if (A.errCode() == DAY_ERROR) {
         cout << "Passed!" << endl;
      }
      else {
         cout << "Your read function does not check the day entry limits after entry," << endl
            << "or it did not set _readErrorCode to DAY_ERROR" << endl;
         ok = false;
      }
      cin.ignore(2000, '\n');
   }
   if (ok) {
      Date A;
      A.dateOnly(true);
      cout << "Day validation, leap year:" << endl;
      cout << "Please enter the following string \"2016/2/29\": ";
      cin >> A;
      cout << "You entered: " << A << endl;
      if (A.errCode() == DAY_ERROR) {
         cout << "Your read function does not check the day entry limits using mday()" << endl;
         ok = false;
      }
      else {
         cout << "passed!" << endl;
      }
      cin.ignore(2000, '\n');
   }
   if (ok) {
      Date A;
      A.dateOnly(false);
      cout << "Hour validation, " << endl;
      cout << "Please enter the following string \"2000/1/1, 25:10\": ";
      cin >> A;
      cout << "You entered: " << A << endl;
      if (A.errCode() == HOUR_ERROR) {
         cout << "Passed!" << endl;
      }
      else {
         cout << "Your read function does not check the hour entry limit after entry," << endl
            << "or it did not set _readErrorCode to HOUR_ERROR" << endl;
         ok = false;
      }
      cin.ignore(2000, '\n');
   }
   if (ok) {
      Date A;
      A.dateOnly(false);
      cout << "Minute validation, " << endl;
      cout << "Please enter the following string \"2000/1/1, 23:60\": ";
      cin >> A;
      cout << "You entered: " << A << endl;
      if (A.errCode() == MIN_ERROR) {
         cout << "Passed!" << endl;
      }
      else {
         cout << "Your read function does not check the minute entry limit after entry," << endl
            << "or it did not set _readErrorCode to MIN_ERROR" << endl;
         ok = false;
      }
      cin.ignore(2000, '\n');
   }
   if (ok) {
      cout << "You passed all error handling tests." << endl << endl
         << " If you have started with test no 1 and came down to here, " << endl
         << " you can now work on Error class." << endl;
   }
   else {
      cout << "You did not pass all the tests, keep working on your project!" << endl;
   }
   return ok;
}

bool ErrorTester_test5() {
   Error T("Testing Error Message");
   Error e;
   bool ok = true;
   int pc = 1;
   cout << T << endl << "Nothing here: >" << e << "<" << endl << "isClear(): " << (e.isClear() ? "Passed!" : "failed!") << endl;
   if (!e.isClear()) ok = false;
   cout << "Testing DMA: " << endl;
   for (int i = 0; i < 10000000; i++) {
      e = "Some error message that is really long long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         ;
      if (i % 100000 == 0) cout << "\r" << pc++ << "%";
   }
   cout << endl << e << endl << "isClear(): " << (e ? "Failed!" : "Passed!") << endl;
   if (e) ok = false;
   e.message("Short Error Message");
   cout << e << " is the same as " << (const char*)e << endl << "isClear(): " << (e.isClear() ? "Failed!" : "Passed!") << endl;
   e.clear();
   cout << "Nothing here: >" << e << "<" << endl << "isClear(): " << (e.isClear() ? "Passed!" : "Failed!") << endl;
   if (!e) ok = false;
   cout << (ok ? "passed" : "Failed") << endl;
   return ok;
}
