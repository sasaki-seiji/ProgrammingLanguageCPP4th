/*
 * Dateandtime.h
 *
 *  Created on: 2016/07/22
 *      Author: sasaki
 */

#ifndef DATEANDTIME_H_
#define DATEANDTIME_H_

#include "Date.h"
#include "Time.h"

#include <iostream>
using std::ostream;

namespace Chrono {

class Date_and_time {
	Date d;
	Time t;
public:
	Date_and_time(Date dd, Time tt) :d{dd}, t{tt} { };
	Date_and_time(int dd, Month mm, int yy, Time tt)
	: d{dd,mm,yy}, t{tt} { };

	int day() const { return d.day(); }
	Month month() const { return d.month(); }
	int year() const { return d.year(); }
	int hour() const { return t.hour(); }
	int minute() const { return t.minute(); }
	int second() const { return t.second(); }

};

ostream& operator<<(ostream& os, const Date_and_time& dt);

} /* namespace Chrono */

#endif /* DATEANDTIME_H_ */
