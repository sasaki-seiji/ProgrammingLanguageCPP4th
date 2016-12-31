/*
 * Date.h
 *
 *  Created on: 2016/07/20
 *      Author: sasaki
 */

#ifndef DATE_H_
#define DATE_H_

#include <string>
using std::string;
#include <iostream>
using std::ostream;
using std::istream;

namespace Chrono {

	enum class Month { jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

	class Date {
	public:
		class Bad_date { };

		explicit Date(int dd ={}, Month mm = {}, int yy = {});

		int day() const;
		Month month() const;
		int year() const;

		string string_rep() const;
		void char_rep(char s[], int max) const;

		Date& add_year(int n);
		Date& add_month(int n);
		Date& add_day(int n);
	private:
		bool is_valid();
		int d;
		Month m;
		int y;

	public:
		static const int ndays_tbl[][13];
	};

	inline int Date::day() const { return d; }
	inline Month Date::month() const { return m; }
	inline int Date::year() const { return y; }

	// helper functions

	int diff(Date a, Date b);	// have to implement later

	bool is_date(int d, Month m, int y);
	bool is_leapyear(int y);

	inline bool operator==(Date a, Date b)
	{
		return a.day()==b.day() && a.month()==b.month() && a.year()==b.year();
	}
	inline bool operator!=(Date a, Date b)
	{
		return !operator==(a,b);
	}
	bool operator<(Date a, Date b);
	bool operator>(Date a, Date b);

	const Date& default_date();

	Date next_weekdy(Date d);	// have to implement later
	Date next_saturday(Date d);	// have to implement later

	inline Date& operator++(Date& d) { return d.add_day(1); }
	inline Date& operator--(Date& d) { return d.add_day(-1); }

	inline Date& operator+=(Date& d, int n) { return d.add_day(n); }
	inline Date& operator-=(Date& d, int n) { return d.add_day(-n); }

	inline Date operator+(Date d, int n) { return d+=n; }
	inline Date operator-(Date d, int n) { return d-=n; }

	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date&d);
} /* namespace Chrono */

#endif /* DATE_H_ */
