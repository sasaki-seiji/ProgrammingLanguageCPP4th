/*
 * Date.h
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#ifndef DATE_H_
#define DATE_H_

struct { int d, m, y; } date_initializer = {1, 1, 1970};

class Date {
	int d {date_initializer.d};
	int m {date_initializer.m};
	int y {date_initializer.y};
public:
	Date(int, int, int);
	Date(int, int);
	Date(int);
	Date();
	Date(const char*);

	void print();
};

void print_initializer_address();

#endif /* DATE_H_ */
