/*
 * Date.h
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */

#ifndef DATE_H_
#define DATE_H_

class Date {
public:
	Date(int dd =0, int mm =0, int yy =0);
	Date& add_day(int n);
	Date& add_month(int n);
	Date& add_year(int n);

	void print();
private:
	int d, m, y;
};

inline bool leapyear(int y)
{
	return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}

#endif /* DATE_H_ */
