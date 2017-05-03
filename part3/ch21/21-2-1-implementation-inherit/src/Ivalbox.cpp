/*
 * Ivalbox.cpp
 *
 *  Created on: 2017/05/03
 *      Author: sasaki
 */

#include "Ivalbox.h"
#include <iostream>
using namespace std;

void Ival_box::set_value(int i)
{
	if (low <= i && i<= high) {
		changed = true;
		val = i;
	}
}

void Ival_box::reset_value(int i)
{
	if (low <= i && i <= high) {
		changed = false;
		val = i;
	}
}

void Ival_box::display_info() const
{
	cout << boolalpha;
	cout << "Ival_box(left=" << left() << ",top=" << top()
			<< ",width=" << width() << ",height=" << height()
			<< ",visible=" << is_visible()
			<< ",value=" << val << ",changed=" << changed << ")" << endl;
}


