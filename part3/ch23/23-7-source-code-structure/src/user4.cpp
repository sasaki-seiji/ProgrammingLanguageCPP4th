/*
 * user4.cpp
 *
 *  Created on: 2016/09/17
 *      Author: sasaki
 */


namespace MyLib {
	int cerr = 0x23456789;
}

//#define std MyLib
	// extern ostream cerr;  /// Linked to standard error (unbuffered)
#include "out.h"

void user4()
{
	out(2);
}

