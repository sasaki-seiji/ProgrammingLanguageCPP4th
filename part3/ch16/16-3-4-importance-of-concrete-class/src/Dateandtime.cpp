/*
 * Dateandtime.cpp
 *
 *  Created on: 2016/07/22
 *      Author: sasaki
 */

#include "Dateandtime.h"

#include <iostream>
using namespace std;

namespace Chrono {

ostream& operator<<(ostream& os, const Date_and_time& dt)
{
	os << dt.year() << '/' << (int)dt.month() << '/' << dt.day() << ' '
			<< dt.hour() << ':' << dt.minute() << ':' << dt.second();

	return os;
}

} /* namespace Chrono */
