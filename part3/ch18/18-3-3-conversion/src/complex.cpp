/*
 * complex.cpp
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

#include "complex.h"
#include <ostream>
using namespace std;

ostream& operator<<(ostream& os, complex a)
{
	os << "(" << a.real() << ", " << a.imag() << ")";
	return os;
}
