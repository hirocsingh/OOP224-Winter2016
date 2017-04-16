/* Name : Avinash Singh
 * OOP244 Section B
 * 27 - March -2017
 * Workshop 9
 */

#ifndef SICT_STRING_H_
#define SICT_STRING_H_

#include <iostream>

#define STRING_BUFFERSIZE 100

namespace ict
{

    

    class String
    {
        // the raw string buffer
        // For in-lab you should assume that 100 chars is enough for all inputs
        // and all test cases
        char m_pString[STRING_BUFFERSIZE];
        
    public:
        
        String();                       // default constructor
        String(const char* src);        // constructor from C-string
        String(const String& src);      // copy constructor
        String& operator=(const String& src); // assignment operator
        ~String();                      // destructor

        int capacity    ()              { return STRING_BUFFERSIZE; }
        
        // the length of the string
        int         length()                    const;
        // returns true if the string is ""
        bool        empty   ()                  const;

        // concatenate a char to the end of the string
        String&     operator+=  (char c);
        // concatenate two strings
        String&     operator+=  (const String& s2);
        // adds two strings and returns it
        String      operator+   (const String& s2) const;
        // returns a pointer to the internal string
        operator    const char* ()                  const;
        // operator wrapper for empty()
        operator    bool        ()                  const;
        // true if string *this and s2 are equal
        bool        operator==(const String& s2)const;
        
   };

    // global helper functions
    // output extraction operator
    std::ostream&    operator<<  (std::ostream&, const String&);
    // input insertion operator
    std::istream&    operator>>  (std::istream&, String&);
  
};

#endif
