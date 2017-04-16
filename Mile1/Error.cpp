/* Author : Avinash Singh
 * OOP244 Section B
 * ID : 115408163
 * Milestone 1
 * File : Error.cpp
 * Date : 2017 - March - 11
 */

#define _CRT_SECURE_NO_WARNINGS

#include "Error.h"
#include <iostream>
#include <cstring>
#include <string>

namespace ict{
    // constructors===================================
    Error::Error(){
        m_message = nullptr;
    }
    Error::Error(const char* errorMessage){
        m_message = nullptr;
        message(errorMessage);
    }

    // operator= for c-style strings==================
    void Error::operator=(const char* errorMessage){
        delete [] m_message;
        m_message = new char[strlen(errorMessage) + 1];
        strcpy(m_message,errorMessage);
    }

    // methods========================================
    void Error::clear(){
        delete [] m_message;
        m_message = nullptr;
    }
    bool Error::isClear()const{
        return m_message == nullptr;
    }
    void Error::message(const char* value){
        delete [] m_message;
        m_message = new char[strlen(value) + 1];
        strcpy(m_message,value);
    }

    // cast overloads=================================
    Error::operator bool()const{
        return m_message == nullptr;
    }
    Error::operator const char*() const{
        return m_message;
    }

    // operator << overload prototype for cout========
    std::ostream& operator<<(std::ostream& cout, const Error& E){
        if(!E.isClear())
            return cout << E.operator const char *();
        else
            return cout << "0";

    }

}
