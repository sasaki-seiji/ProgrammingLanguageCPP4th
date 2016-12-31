/*
 * Date.cpp
 *
 *  Created on: 2016/07/20
 *      Author: sasaki
 */

#include "Date.h"
#include <locale>
#include <sstream>
using namespace std;

namespace Chrono {

const int Date::ndays_tbl[][13] = {
	//  jan,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

Date::Date(int dd, Month mm, int yy)
	:d{dd}, m{mm}, y{yy}
{
	if (y == 0) y = default_date().year();
	if (m == Month{}) m = default_date().month();
	if (d == 0) d = default_date().day();

	if (!is_valid()) throw Bad_date();
}

const Date& default_date()
{
	static Date d {1, Month::jan, 1970};
	return d;
}

Date& Date::add_year(int n)
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

Date& Date::add_month(int n)
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

Date& Date::add_day(int n)
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

bool Date::is_valid()
{
	return is_date(d,m,y);
}

bool is_date(int d, Month m, int y)
{
	int mm = static_cast<int>(m);
	if (d < 1 || mm < 1 || y < 1) return false;

	bool leap = is_leapyear(y);
	int ndays = Date::ndays_tbl[leap][mm];
	if (d > ndays) return false;

	return true;
}

bool is_leapyear(int y)
{
	return y%400 == 0 || ( y%100 != 0 && y%4 == 0);
}

bool operator<(Date a, Date b)
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

bool operator>(Date a, Date b)
{
	if (a.year() > b.year()) {
		return true;
	}
	else if (a.year() < b.year()) {
		return false;
	}

	if (a.month() > b.month()) {
		return true;
	}
	else if (a.month() < b.month()) {
		return false ;
	}

	if (a.day() > b.day()) {
		return true;
	}
	else {
		return false;
	}
}

// 2016.12.31 add
ostream& operator<<(ostream& os, const Date& d)
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

// 2016.12.31 change
istream& operator>>(istream& is, Date&d)
{
	if (istream::sentry guard{is}) {
		ios_base::iostate err = ios_base::goodbit;
		struct tm t;
		use_facet<time_get<char>>(is.getloc()).get_date(is,0,is,err,&t);
		//use_facet<time_get<char>>(is.getloc()).get_date(is,time_get<char>::iter_type(),is,err,&t);
		if (!err){
			Month m = static_cast<Month>(t.tm_mon+1);
			d = Date(t.tm_mday, m, t.tm_year+1900);
		}
		is.setstate(err);
	}
	return is;
}

} // Chrono
