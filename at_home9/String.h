#ifndef ICT_STRING_H_
#define ICT_STRING_H_

#include <iostream>


namespace sict
{
    class String
    {
        // the raw string buffer
        char *m_pString;
        
        // the capacity of this buffer
        int m_capacity;     // note: this is not the length of the string!
    public:
        // the default constructor
        String(int size=1);
        // a constructor from a char-string
        String(const char* src, int size=1);
        // a copy constructor
        String(const String& src, int size=1);
        // the assignment operator
        String& operator=(const String& src);
        // the destructor
        ~String();


        // a method to resize the buffer
        virtual void resize (int newsize);
        // method to return the current capacity of the buffer
        int capacity    ()              { return m_capacity; }
        

        // method to return the length of the string
        int         length()                    const;
        // true if the string is empty
        bool        empty   ()                  const;
        // return a substring of the string
        String      substr  (int index, int len)const;

        // operators functions
        // add a char to the end of the string
        String&     operator+=  (char c);
        // append a string to the end of this one
        String&     operator+=  (const String& s2);
        // return string A + string B
        String      operator+   (const String& s2) const;
        // cast the string as a C-style string
        operator    const char* ()                  const;
        // true if the string is valid, false if empty
        operator    bool        ()                  const;
        // true if string 1 == string 2
        bool        operator==(const String& s2)const;
        
        
        
   };

    // global helper functions
    std::ostream&    operator<<  (std::ostream&, const String&);
    std::istream&    operator>>  (std::istream&, String&);



   

};

#endif
