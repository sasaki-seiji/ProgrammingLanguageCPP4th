/*
 * Date.cpp
 *
 *  Created on: 2016/07/28
 *      Author: sasaki
 */

#include "Date.h"

ostream& operator<<(ostream& os, Date date)
{
	os << date.year() << '/' << date.month() << '/' << date.day();
	return os;
}
