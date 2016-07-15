/*
 * Date3.h
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#ifndef DATE3_H_
#define DATE3_H_

class Date3 {
public:
	Date3(int dd, int mm, int yy);
	void add_year(int n);
	void print();
private:
	int d, m, y;
};

#endif /* DATE3_H_ */
