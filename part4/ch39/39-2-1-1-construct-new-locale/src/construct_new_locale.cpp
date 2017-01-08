/*
 * construct_new_locale.cpp
 *
 *  Created on: 2017/01/08
 *      Author: sasaki
 */

#include "Money.h"
using namespace std;

void f(const locale& loc, const My_money_io* mio)
{
	locale loc1(locale{"POSIX"}, loc, locale::monetary);
	locale loc2 = locale(locale::classic(), mio);

	cout << "loc1:curr_symbol=\""
			<< use_facet<moneypunct<char>> (loc1).curr_symbol() << "\"\n";
	cout << "loc2:curr_symbol=\""
			<< use_facet<moneypunct<char,true>> (loc2).curr_symbol() << "\"\n";
}

void g(const locale::facet* mio1, const moneypunct<char,true>* mio2)
{
	//locale loc3 = locale(locale::classic(), mio1);
		// error: ‘id’ is not a member of ‘const std::locale::facet’
	locale loc4 = locale(locale::classic(), mio2);
}

int main()
{
	locale loc {"en_US.UTF-8"};
	f(loc, new My_money_io);

	g(new My_money_io, new My_money_io);
}
