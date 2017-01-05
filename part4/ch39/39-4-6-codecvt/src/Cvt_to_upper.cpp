/*
 * Cvt_to_upper.cpp
 *
 *  Created on: 2017/01/05
 *      Author: sasaki
 */

#include <climits>
#include <iostream>
#include "Cvt_to_upper.h"
using namespace std;

codecvt<char,char,mbstate_t>::result
Cvt_to_upper::do_in(
	State& s,
	const char* from, const char* from_end, const char*& from_next,
	char* to, char* to_end, char*& to_next) const
{
	cerr << "do_in" << endl;

	for( ; from!=from_end && to!=to_end; ++from, ++to)
		*to = toupper(*from);
	from_next = from;
	to_next = to;

	return from==from_end ? ok : partial;
}

codecvt<char,char,mbstate_t>::result
Cvt_to_upper::do_out(
	State& s,
	const char* from, const char* from_end, const char*& from_next,
	char* to, char* to_end, char*& to_next) const
{
	return codecvt<char,char,mbstate_t>::do_out(s,from,from_end,from_next,to,to_end,to_next);
}

int Cvt_to_upper::do_length(
	State&, const char* from, const char* from_end, size_t max) const
{
	int len = from_end - from;
	if (len > max)
		len = max;
	cerr << "do_length() returns " << len << endl;
	return len;
}

int Cvt_to_upper::do_max_length() const noexcept
{
	return INT_MAX;
}




