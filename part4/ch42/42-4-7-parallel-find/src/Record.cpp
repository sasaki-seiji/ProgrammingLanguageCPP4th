/*
 * Record.cpp
 *
 *  Created on: 2017/01/28
 *      Author: sasaki
 */


#include <iostream>
#include "Record.h"
using namespace std;

ostream& operator<<(ostream& os, const Record& r)
{
	os << "price=" << r.price << ", color=";
	switch(r.color) {
	case Color::red:
		os << "red"; break;
	case Color::green:
		os << "green"; break;
	case Color::blue:
		os << "blue"; break;
	}

	return os;
}

