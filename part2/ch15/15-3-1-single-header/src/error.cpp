/*
 * error.cpp
 *
 *  Created on: 2016/07/11
 *      Author: sasaki
 */


#include "dc.h"
#include <string>
#include <iostream>
using namespace std;

int Error::no_of_errors;

double Error::error(const string& s)
{
	no_of_errors++;
	cerr << "error: " << s << '\n';
	return 1;
}


