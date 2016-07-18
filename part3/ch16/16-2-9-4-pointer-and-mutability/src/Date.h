/*
 * Date.h
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */

#ifndef DATE_H_
#define DATE_H_

#include <string>
using std::string;

struct cache {
	bool valid;
	string rep;
};

class Date {
public:
	Date(int dd =0, int mm =0, int yy =0);

	int day() const { return d; }
	int month() const { return m; }
	int year() const ;

	void add_day(int n) { d += n; }
	void add_month(int n) { m += n; }
	void add_year(int n);

	string string_rep() const;
private:
	cache* c;
	void compute_cache_value() const;

	int d, m, y;
};

inline void Date::add_year(int n)
{
	y += n;
}

#endif /* DATE_H_ */
