/*
 * slice.cpp
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#include "slice.h"

slice slice::all {0,(size_t)-1,1};

ostream& operator<<(ostream& os, const slice& s)
{
	os << "start: " << s.start
			<< ", length: " << s.length
			<< ", stride: " << s.stride;
	return os;
}


