/*
 * Date.cpp
 *
 *  Created on: 2016/07/20
 *      Author: sasaki
 */

#include "Date.h"

namespace {
	const int ndays_tbl[][13] = {
			//  jan,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
			{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
}

Chrono::Date::Date(int dd, Month mm, int yy)
	:d{dd}, m{mm}, y{yy}
{
	if (y == 0) y = default_date().year();
	if (m == Month{}) m = default_date().month();
	if (d == 0) d = default_date().day();

	if (!is_valid()) throw Bad_date();
}

const Chrono::Date& Chrono::default_date()
{
	static Date d {1, Month::jan, 1970};
	return d;
}

Chrono::Date& Chrono::Date::add_year(int n)
{
	y += n;
	if (y < 1) throw Bad_date{};

	bool leap = is_leapyear(y);
	int mm = static_cast<int>(m);
	int ndays = ndays_tbl[leap][mm];
	if (d > ndays) { // feb 29th
		d -= ndays;
		++mm;
	}
	m = static_cast<Month>(mm);

	return *this;
}

Chrono::Date& Chrono::Date::add_month(int n)
{
	if (n==0) return *this;

	if (n>0) {
		int delta_y = n/12;
		int mm = static_cast<int>(m) + n%12;
		if (12 < mm) {
			++delta_y;
			mm -= 12;
		}
		y += delta_y;

		bool leap = is_leapyear(y);
		int ndays = ndays_tbl[leap][mm];
		if (d > ndays) {
			d -= ndays;
			++mm;
		}
		m = static_cast<Month>(mm);
		return *this;
	}

	else {
		int abs_n = -n;
		int delta_y = abs_n/12;
		int mm = static_cast<int>(m) - abs_n%12;
		if (mm < 1) {
			++delta_y;
			mm += 12;
		}
		y -= delta_y;
		if (y < 1) throw Bad_date{};

		bool leap = is_leapyear(y);
		int ndays = ndays_tbl[leap][mm];
		if (d > ndays) {
			d -= ndays;
			++mm;
		}
		m = static_cast<Month>(mm);
		return *this;
	}
}

Chrono::Date& Chrono::Date::add_day(int n)
{
	if (n == 0) return *this;

	if (n > 0) {
		d += n;
		int mm = static_cast<int>(m);
		bool leap = is_leapyear(y);
		int ndays = ndays_tbl[leap][mm];

		while (d > ndays) {
			d -= ndays;
			++mm;
			if (mm > 12) {
				mm = 1;
				++y;
			}
			leap = is_leapyear(y);
			ndays = ndays_tbl[leap][mm];
		}
		m = static_cast<Month>(mm);
	}

	else {
		d += n;

		int mm = static_cast<int>(m);
		while (d < 1) {
			--mm;
			if (mm < 1) {
				mm = 12;
				--y;
			}
			bool leap = is_leapyear(y);
			int ndays = ndays_tbl[leap][mm];
			d += ndays;
		}
		m = static_cast<Month>(mm);
	}

	if (y < 1) throw Bad_date{};
	return *this;
}

bool Chrono::Date::is_valid()
{
	return is_date(d,m,y);
}

bool Chrono::is_date(int d, Month m, int y)
{
	int mm = static_cast<int>(m);
	if (d < 1 || mm < 1 || y < 1) return false;

	if (mm > 12) return false;

	bool leap = is_leapyear(y);
	int ndays = ndays_tbl[leap][mm];
	if (d > ndays) return false;

	return true;
}

bool Chrono::is_leapyear(int y)
{
	return y%400 == 0 || ( y%100 != 0 && y%4 == 0);
}

bool Chrono::operator<(Date a, Date b)
{
	if (a.year() < b.year()) {
		return true;
	}
	else if (a.year() > b.year()) {
		return false;
	}

	if (a.month() < b.month()) {
		return true;
	}
	else if (a.month() > b.month()) {
		return false ;
	}

	if (a.day() < b.day()) {
		return true;
	}
	else {
		return false;
	}
}

bool Chrono::operator>(Date a, Date b)
{
	return !( a==b || a<b );
}

ostream& Chrono::operator<<(ostream& os, const Date& d)
{
	os << d.year() << '.' << static_cast<int>(d.month()) << '.' << d.day();
	return os;
}

istream& Chrono::operator>>(istream& is, Date&d)
{
	string s;
	int year, month, day;

	if (is >> s) {
		sscanf(s.c_str(), "%d%*c%d%*c%d", &year, &month, &day);
		d = Date{day, static_cast<Month>(month), year};
	}

	return is;
}

