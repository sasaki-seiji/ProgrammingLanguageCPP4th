/*
 * Debuginfo.cpp
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#include "Debuginfo.h"

ostream& operator<<(ostream& os, const Debug_info& di)
{
	for (auto x : di)
		os << x << ", ";
	return os;
}

Debug_info merge_info(Debug_info di1, Debug_info di2)
{
	di1.merge(di2);
	return di1;
}

