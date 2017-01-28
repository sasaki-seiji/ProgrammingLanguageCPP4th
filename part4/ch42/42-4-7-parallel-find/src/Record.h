/*
 * Record.h
 *
 *  Created on: 2017/01/28
 *      Author: sasaki
 */

#ifndef RECORD_H_
#define RECORD_H_

#include <iostream>
enum class Color { red, green, blue };

struct Record {
	int price;
	Color color;
};

const int grain = 50000;
std::ostream& operator<<(std::ostream& os, const Record& r);

#endif /* RECORD_H_ */
