//
//  PosIO.h
//  OOP_Mileston3
//
//  Created by Avinash Singh on 17/03/17.
//  Copyright © 2017 Avinash Singh. All rights reserved.
//

#ifndef ICT_POSIO_H__
#define ICT_POSIO_H__
// includes go here
#include<iostream>
#include<fstream>
using namespace std;


// ict namespace
namespace ict{
   class PosIO{
   public:
      // pure virutal methods go here
      //virtual ~PosIO();
      virtual std::ostream& write(std::ostream& os, bool linear)const = 0;
      virtual std::istream& read(std::istream& is)= 0;
   };
}


#endif
