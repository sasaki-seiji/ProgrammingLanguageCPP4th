/*
 * Date2.h
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#ifndef DATE2_H_
#define DATE2_H_

class Date2 {
	int d, m, y;
public:
	Date2(int dd, int mm, int yy);
	Date2(int dd, int mm);
	Date2(int dd);
	Date2();
	Date2(const char*);

	void print();
};

#endif /* DATE2_H_ */
