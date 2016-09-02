/*
 * Date.h
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#ifndef DATE_H_
#define DATE_H_

struct Date {
	int y,m,d;
};

class My_date : public Date {
public:
	My_date(int yy, int mm, int dd) : Date{yy,mm,dd} { }
};

#endif /* DATE_H_ */
