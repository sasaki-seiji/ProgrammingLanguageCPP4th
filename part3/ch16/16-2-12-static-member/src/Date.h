/*
 * Date.h
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */

#ifndef DATE_H_
#define DATE_H_

class Date {
	int d, m, y;
	static Date default_date;
public:
	Date(int dd =0, int mm =0, int yy =0);
	static void set_default(int dd, int mm, int yy);

	void print();
};

#endif /* DATE_H_ */
