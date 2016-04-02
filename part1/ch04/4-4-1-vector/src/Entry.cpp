/*
 * Entry.cpp
 *
 *  Created on: 2016/04/02
 *      Author: sasaki
 */

#include "Entry.h"

ostream& operator<<(ostream& os, const Entry& e)
{
	return os << "{\"" << e.name << "\", " << e.number << "}";
}

istream& operator>>(istream& is, Entry& e)
{
	char c, c2;
	if (is>>c && c=='{' && is>>c2 && c2=='"') {
		string name;
		while (is.get(c) && c!='"')
			name+=c;

		if (is>>c && c==',') {
			int number;
			if (is>>number>>c && c=='}') {
				e = {name, number};
				return is;
			}
		}
	}

	is.setstate(ios_base::failbit);
	return is;
}
