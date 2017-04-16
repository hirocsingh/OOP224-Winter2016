// Final Project Milestone 2
// Tester program
// File	MyFile.cpp
// Version 1.0
// Date	3/15/2017
// Author	Fardad Soleimanloo
//

/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "MyFile.h"
using namespace std;
namespace ict{

  MyFile::MyFile(const char* fname){
    _text[0] = char(0);
    strcpy(_fname, fname);
  }
  fstream& MyFile::save(std::fstream& file)const{
    file.open(_fname, ios::app|ios::out);
    int i = 0;
    while (_text[i]){
      file << _text[i];
      i++;
    }
    file.close();
    return file;
  }
  fstream& MyFile::load(std::fstream& file){
    file.open(_fname, ios::in);
    int i=0;
    while (!file.fail()){
      _text[i++] = file.get();
    }
    file.clear();
    file.close();
    if(i > 0) i--;
    _text[i] = 0;
    return file;
  }
  ostream& MyFile::write(std::ostream& os, bool linear)const{
    for (int i = 0; _text[i]; i++){
      if (linear && _text[i] == '\n'){
        os << " ";
      }
      else{
        os << _text[i];
      }
    }
    return os;
  }
  istream& MyFile::read(std::istream& is){
    is.getline(_text, 9999, EOF);
    return is;
  }
  void MyFile::print(){
    write(cout, false);
    cout << endl;
  }
  std::ostream& operator<<(std::ostream& ostr, const MyFile& mf){
    return mf.write(ostr, true);
  }
  std::istream& operator>>(std::istream& istr, MyFile& mf){
    return mf.read(istr);
  }
}
