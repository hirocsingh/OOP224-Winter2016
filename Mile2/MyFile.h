// Final Project Milestone 2
// Tester program
// File	MyFile.h
// Version 1.0
// Date	3/15/2017
// Author	Fardad Soleimanloo

/////////////////////////////////////////////////////////////////
#ifndef ICT_MYFILE_H__
#define ICT_MYFILE_H__
#include "PosIO.h"
namespace ict{
  class MyFile : public PosIO {
    char _fname[256];
    char _text[10000];
  public:
    MyFile(const char* fname);
    std::fstream& save(std::fstream& file)const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear)const;
    std::istream& read(std::istream& is);
    void print();
  };
  std::ostream& operator<<(std::ostream& ostr, const MyFile& mf);
  std::istream& operator>>(std::istream& istr, MyFile& mf);
}
#endif
