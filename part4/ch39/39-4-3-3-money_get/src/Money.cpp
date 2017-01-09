/*
 * Money.cpp
 *
 *  Created on: 2017/01/04
 *      Author: sasaki
 */

#include <locale>
#include "Money.h"
using namespace std;

const My_money_io::pattern My_money_io::pat { sign, symbol, value, none };

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

ostream& operator<<(ostream& s, Money m)
{
	ostream::sentry guard(s);
	if (!guard) return s;

	try {
		const auto& f = use_facet<money_put<char>>(s.getloc());

		auto d = static_cast<long double>(m.amount);
		auto m2 = static_cast<long long>(d);
		if (m2 == m.amount) {
			if (f.put(s, true, s, s.fill(), d).failed())
				s.setstate(ios_base::badbit);
		}
		else
			s.setstate(ios_base::badbit);
	}
	catch (...) {
		handle_ioexception(s);
	}
	return s;
}

istream& operator>>(istream& s, Money& m)
{
	istream::sentry guard(s);
	if (guard) try {
		ios_base::iostate state = ios_base::goodbit;
		string str;
		long double ld;

		const auto& f = use_facet<money_get<char>>(s.getloc());

		f.get(s, istreambuf_iterator<char>{}, true, s, state, str);

		if (state==0 || state==ios_base::eofbit) {
			long long i = stoll(str);
			if (errno==ERANGE) {
				state |= ios_base::failbit;
			}
			else {
				m.amount = i;
			}
		}
		s.setstate(state);
	}
	catch (...) {
		handle_ioexception(s);
	}
	return s;
}
