/*
 * Season.cpp
 *
 *  Created on: 2017/01/06
 *      Author: sasaki
 */


#include <iostream>
#include <algorithm>
#include "Season.h"
using namespace std;

locale::id Season_io::id;

ostream& operator<<(ostream& os, Season x)
{
	locale loc {os.getloc()};

	if (has_facet<Season_io>(loc))
		return os << use_facet<Season_io>(loc).to_str(x);
	return os << static_cast<int>(x);
}

istream& operator>>(istream& is, Season& x)
{
	const locale& loc {is.getloc()};

	if (has_facet<Season_io>(loc)) {
		const Season_io& f {use_facet<Season_io>(loc)};

		string buf;
		if (!(is>>buf && f.from_str(buf,x)))
			is.setstate(ios_base::failbit);
		return is;
	}

	int i;
	is >> i;
	x = static_cast<Season>(i);
	return is;
}


string Season_io::to_str(Season x) const
{
	return m.get(cat,0,x,"no-such-season");
}

bool Season_io::from_str(const string& s, Season& x) const
{
	for (int i = Season::spring; i<= Season::winter; i++)
		if (m.get(cat,0,i,"no-such-season") == s) {
			x = Season(i);
			return true;
		}
	return false;
}
