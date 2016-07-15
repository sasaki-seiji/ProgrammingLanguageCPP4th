/*
 * Date2.h
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#ifndef DATE2_H_
#define DATE2_H_

struct Date2 {
private:
	int d, m, y;
public:
	Date2(int dd, int mm, int yy);
	void add_year(int n);

	void print();
};

#endif /* DATE2_H_ */
