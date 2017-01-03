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

void handle_ioexception(istream& is)
{
	if (is.exceptions()&ios_base::badbit) {
		try {
			is.setstate(ios_base::badbit);
		}
		catch (...) {

		}
		throw;
	}
	is.setstate(ios_base::badbit);
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

istream& operator>>(istream& is, Double& d)
{
	istream::sentry guard(is);
	if (!guard) return is;

	ios_base::iostate state = ios_base::goodbit;
	istreambuf_iterator<char> eos;
	try {
		double dd;
		use_facet<num_get<char>>(is.getloc()).get(is,eos,is,state,dd);
		if (state == ios_base::goodbit || state == ios_base::eofbit) d = {dd};
		is.setstate(state);
	}
	catch (...) {
		handle_ioexception(is);
	}
	return is;
}
