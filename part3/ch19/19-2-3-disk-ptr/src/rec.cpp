/*
 * rec.cpp
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */

#include "rec.h"

istream& operator>>(istream& is, Rec& rec)
{
	is >> rec.name;
	is >> rec.count;
	return is;
}

ostream& operator<<(ostream& os, const Rec& rec)
{
	os << rec.name << '\n';
	os << rec.count << '\n';
	return os;
}

