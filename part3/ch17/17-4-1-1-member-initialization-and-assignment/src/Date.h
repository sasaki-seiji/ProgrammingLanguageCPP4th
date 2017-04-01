/*
 * Date.h
 *
 *  Created on: 2016/07/28
 *      Author: sasaki
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
using std::ostream;

class Date {
	int d,m,y;
public:
	Date(int dd, int mm, int yy) : d{dd}, m{mm}, y{yy} { } ;
	int year() const { return y; }
	int month() const { return m; }
	int day() const { return d; }
};

ostream& operator<<(ostream&, Date);

#endif /* DATE_H_ */
