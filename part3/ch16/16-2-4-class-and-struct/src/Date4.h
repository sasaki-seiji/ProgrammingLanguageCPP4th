/*
 * Date4.h
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#ifndef DATE4_H_
#define DATE4_H_

class Date4 {
public:
	Date4(int dd, int mm, int yy);
private:
	int d, m, y;
public:
	void add_year(int n);
	void print();
};

#endif /* DATE4_H_ */
