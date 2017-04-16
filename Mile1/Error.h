/* Author : Avinash Singh
 * OOP244 Section B
 * ID : 115408163
 * Milestone 1
 * File : Error.h
 * Date : 2017 - March - 11
 */

// compilation safegaurds
#ifndef ICT_ERROR_H_
#define ICT_ERROR_H_


#include <iostream>
namespace ict {
   class Error {
      char* m_message;
   public:
   // constructors
    Error();
    Error(const char* errorMessage);


   // destructor
       virtual ~Error(){
           delete [] m_message;
       }

   // deleted constructor and operator=
   Error(const Error& em) = delete;
   Error& operator=(const Error& em) = delete;

   // operator= for c-style strings
   void operator=(const char* errorMessage);

   // methods
   void clear();
   bool isClear()const;
   void message(const char* value);

   // cast overloads
   operator bool()const;
   operator const char*() const;

   };
   // operator << overload prototype for cout
   std::ostream& operator<<(std::ostream& cout, const Error& D);
}

#endif
