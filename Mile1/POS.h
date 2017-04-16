/* Author : Avinash Singh
 * OOP244 Section B
 * ID : 115408163
 * Milestone 1
 * File : POS.h
 * Date : 2017 - March - 11
 */

// compilation safeguards
#ifndef ICT_POSAPP_H__
#define ICT_POSAPP_H__

namespace ict{
	// defined values
    const double TAX = 0.13; //The tax rate for the goods
	#define MAX_SKU_LEN 7 //The maximum size of an SKU code
	#define MIN_YEAR 2000 //The min year used to validate year input
	#define MAX_YEAR 2030 //The max year used to validate year input
	#define MAX_NO_ITEMS 2000 //The maximum number of records in the data file.
}

#endif
