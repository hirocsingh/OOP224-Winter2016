
#include <iostream>
#include <cmath>
#include "data.h"


using namespace std;

/////////////////////////////
// min
//
// returns the smallest item in the array
//
int min(const int* data, int N) 
{
    int ret = LARGEST_NUMBER;
    for (int i=0; i < N; i++)
    {
        if (data[i] < ret)
        {
            ret = data[i];
        }
    }
    return ret;
}
    
 
   
