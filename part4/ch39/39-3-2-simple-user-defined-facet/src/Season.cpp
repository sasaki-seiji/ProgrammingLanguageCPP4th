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


const string US_season_io::seasons[] = {
	"spring",
	"summer",
	"fall",
	"winter"
};

const string& US_season_io::to_str(Season x) const
{
	if (x<spring || winter<x) {
		static const string ss = "no-such-season";
		return ss;
	}
	return seasons[x];
}

bool US_season_io::from_str(const string& s, Season& x) const
{
	const string* p = find(begin(seasons), end(seasons), s);
	if (p==end(seasons))
		return false;

	x = Season(p-begin(seasons));
	return true;
}
