#include <cstring>
#include <iostream>
#include "String.h"


using namespace std;

namespace sict{


   //////////////////////////////////////////////////////
   //
   // Default Constructor
   // String::String(int capacity);
   //
   // initialize the string with an internal buffer capacity of
   // "capacity."
   // default capacity is 1 (minimum needed for an empty string)
   //
   //
   String::String(int capacity){
      m_capacity = capacity;
      m_pString = new char[m_capacity];
      m_pString[0] = '\0' ;
   }

   //////////////////////////////////////////////////////
   //
   // String::String(const char* p, int capacity);
   //
   // Construct a String from a char array
   // Should initialize the internal buffer to at least
   // the length of the string need to hold pSource,
   // or capacity, whichever is greater.
   //
   //
   String::String(const char* pSource, int capacity){
      int lenght = (int)strlen(pSource);
      m_capacity = capacity;
      if(lenght > m_capacity)
         m_pString = new char[lenght];
      else
         m_pString = new char[m_capacity];
      strcpy(m_pString,pSource);
   }

   //////////////////////////////////////////////////////
   //
   // String::String(const String &s, int capacity);
   //
   // Copy constructor
   //
   // Construct a String from another String
   //
   //
   String::String(const String& other, int capacity)
   {
      m_capacity = (int)strlen(other.m_pString);
      if(other.m_pString != nullptr)
         m_pString = new char[m_capacity];
      *this = other;
   }



   //////////////////////////////////////////////////////
   //
   // String::resize(int newsize)
   //
   // resize the internal buffer to the value given
   // do NOT shrink the string buffer smaller than
   // that needed to hold the existing string!
   // (length + 1);
   //
   void String::resize(int newsize)
   {
      int i;
      char* temp;
      temp = nullptr;
      temp = new char[newsize];
      temp[0] = '\0';          //initialize first element
      if (m_pString){
         for (i = 0; (i < newsize -1 && m_pString[i] != '\0'); i++){
            temp[i] = m_pString[i];
         }
         temp[i] = '\0';
      }
      delete[] m_pString;
      m_pString = nullptr;
      m_capacity = 0;
      m_pString = new char[m_capacity = newsize];
      m_pString[0] = '\0';
      if (temp[0] != '\0'){      //nothing to copy
         strcpy(m_pString, temp);
      }
   }


   //////////////////////////////////////////////////////
   //
   // String::operator=(const String& other)
   //
   // Assignment operator
   // copy string "other" to this object
   //
   //
   String& String::operator=(const String& other)
   {
      m_capacity = (int)strlen(other.m_pString);
      if(this != &other){
         delete [] m_pString;
        resize(m_capacity);
         strcpy(m_pString,other.m_pString);
      }
      return *this;
   }


   //////////////////////////////////////////////////////
   //
   // String::~String
   //
   // destructor
   //
   // clean up the internal string buffer
   //
   String::~String()
   {
      delete [] m_pString;
      m_pString = nullptr;
      m_capacity = 0;
   }

   //////////////////////////////////////////////////////
   //
   // String::length()
   //
   // return the length of the string
   //
   //
   int String::length() const
   {
      return strlen(m_pString);
   }


   //////////////////////////////////////////////////////
   //
   // String::operator const char*() const
   //
   // convert the String to a char*
   //
   //
   String::operator const char *() const
   {
      return m_pString;
   }


   //////////////////////////////////////////////////////
   //
   // String::empty()
   //
   //
   // returns true if the string is empty
   // i.e. either the first char is \0, or
   // length is 0.
   bool String::empty() const
   {
      return m_pString[0] == '\0';
   }

   //////////////////////////////////////////////////////
   //
   // String::operator bool()
   //
   // same as empty(), just wrapped in an operator
   //
   //
   String::operator bool() const
   {
      return !empty();
   }


   //////////////////////////////////////////////////////
   //
   // String::operator==(const String& s2) const
   //
   // returns true if *this == s2.
   // You can use the strcmp function to check if
   // two strings are equal, or write your own
   // treating the string as a char-array
   //
   bool String::operator==(const String& s2) const
   {
    	 return (strcmp(this->m_pString,s2.m_pString)==0);
   }


   //////////////////////////////////////////////////////
   //
   // String::operator+=(const String& s2)
   //
   // Concatenates s2 to the end of *this
   //
   // implements *this = (*this + s2)
   // return *this
   //
   //
   String& String::operator+=(const String& s2)
   {
      strcat(this->m_pString,s2.m_pString);
      return *this;
   }



   //////////////////////////////////////////////////////
   //
   // String::operator+(const String& s2) const
   //
   // implements the operator (*this + s2)
   // returns the expression
   // DOES NOT MODIFY *this
   //
   //
   String String::operator+(const String& s2) const
   {
      String temp;
      temp = *this;
      temp += s2;
      return temp;
   }

   //////////////////////////////////////////////////////
   //
   // String::operator+=(char c)
   //
   // Adds a single char c to the end of the string in *this
   // Grows the string buffer if necessary.
   //
   String& String::operator+= (char c)
   {
      this->m_pString[strlen(this->m_pString)] = c;
      this->m_pString[strlen(this->m_pString) + 1] = '\0';
      return *this;
   }



   //////////////////////////////////////////////////////
   //
   // String::substr
   //
   // Returns a substring of the current string. In case of error
   // return an empty String() object instead.
   //
   // return the string slice starting at index, at most len characters
   //
   // both index and len have to lie inside the string. If they do not, then
   // that is an error
   //
   String String::substr(int index, int len) const
   {
      String temp;
      if(len < m_capacity && index < m_capacity){
         for(int i = index; i <= len; i++)
            temp.m_pString[i] = this->m_pString[i];
      }
      return temp;
   }

   //////////////////////////////////////////////////////
   //
   // operator<<
   //
   // Print the string to the output stream
   //
   // clean up the internal string buffer
   //
   std::ostream& operator<<(std::ostream& ostream, const String &s)
   {
      ostream << (const char*)s;
      return ostream;
   }

   //////////////////////////////////////////////////////
   //
   // operator>>
   //
   // Input a string from an input stream into the String s
   //
   // Note: the input can be ANY length in character. You will need to
   // read it one char at a time.
   //
   std::istream& operator>>(std::istream& istream, String &s)
   {
      s = "";
      char tempC = 0;
      do
      {
         tempC = istream.get();
         if (tempC != '\n')
         {
            s += tempC;
         }
         else
            break;
      } while(1);
      return istream;
   }


}
