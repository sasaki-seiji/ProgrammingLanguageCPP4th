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
	// error: conflicting declaration ‘MyLib::ostream MyLib::cerr’
	// extern ostream cerr;  /// Linked to standard error (unbuffered)
#include "out.h"

void user4()
{
	out(2);
}

