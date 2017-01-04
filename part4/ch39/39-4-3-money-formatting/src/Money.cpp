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

