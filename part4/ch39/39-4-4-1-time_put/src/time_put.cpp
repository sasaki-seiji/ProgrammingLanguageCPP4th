/*
 * time_put.cpp
 *
 *  Created on: 2016/12/31
 *      Author: sasaki
 */


#include <locale>
#include <iostream>
#include <sstream>
using namespace std;

#include "Date.h"
using namespace Chrono;

ostream& operator<<(ostream& os, Date d)
{
	ostringstream ss;
	tm t;
	t.tm_mday = d.day();
	t.tm_mon = static_cast<int>(d.month())-1;
	t.tm_year = d.year()-1900;
	char fmt[] ="{%Y-%m-%d}";

	use_facet<time_put<char>>(os.getloc()).put(os,os,' ',&t,begin(fmt),end(fmt));
	return os;
}

int main()
{
	Date d {25, Month::dec, 1959};
	cout << d << endl;
}
