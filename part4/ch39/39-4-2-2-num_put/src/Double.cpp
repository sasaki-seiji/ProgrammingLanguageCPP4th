/*
 * Double.cpp
 *
 *  Created on: 2017/01/03
 *      Author: sasaki
 */


#include "Double.h"
using namespace std;

void handle_ioexception(ostream& os)
{
	if (os.exceptions()&ios_base::badbit) {
		try {
			os.setstate(ios_base::badbit);
		}
		catch (...) {

		}
		throw;
	}
	os.setstate(ios_base::badbit);
}

ostream& operator<<(ostream& os, Double d)
{
	ostream::sentry guard(os);
	if (!guard) return os;

	try {
		if (use_facet<num_put<char>>(os.getloc()).put(os,os,os.fill(),d.v).failed())
			os.setstate(ios_base::badbit);
	}
	catch (...) {
		handle_ioexception(os);
	}
	return os;
}


