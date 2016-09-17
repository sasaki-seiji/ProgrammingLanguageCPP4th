/*
 * accum.cpp
 *
 *  Created on: 2016/09/17
 *      Author: sasaki
 */


#include "accum.h"
#include <numeric>
using namespace std;

double accum(const vector<double>& v)
{
	return accumulate(v.begin(), v.end(), 0.0);
}

