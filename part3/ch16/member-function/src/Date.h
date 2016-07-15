/*
 * Date.h
 *
 *  Created on: 2016/07/15
 *      Author: sasaki
 */

#ifndef DATE_H_
#define DATE_H_

struct Date {
	int d, m, y;

	void init(int dd, int mm, int yy);
	void add_year(int n);
	void add_month(int n);
	void add_day(int n);

	void print();
};

#endif /* DATE_H_ */
