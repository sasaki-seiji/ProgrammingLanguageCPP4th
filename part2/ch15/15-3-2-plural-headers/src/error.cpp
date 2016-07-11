/*
 * error.cpp
 *
 *  Created on: 2016/07/11
 *      Author: sasaki
 */


#include "error.h"
#include <iostream>
using namespace std;

int Error::number_of_errors;
double Error::error(const string& s)
{
	number_of_errors++;
	cerr << "error: " << s << '\n';
	return 1;
}
