/*
 * error.cpp
 *
 *  Created on: 2016/05/24
 *      Author: sasaki
 */

#include <iostream>
using std::cerr;

#include "error.h"

int Error::no_of_errors;

double Error::error(const string& s)
{
	no_of_errors++;
	cerr << "error: " << s << '\n';
	return 1;
}

