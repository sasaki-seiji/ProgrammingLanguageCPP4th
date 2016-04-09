/*
 * exception.cpp
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */

#include <iostream>
#include <stdexcept>
using namespace std;

#include "Vector.h"

void f(Vector& v)
{
	try {
		v[v.size()] = 7;
	}
	catch( out_of_range ) { // warning: Catching by reference is recommended
		cout << "caught out_of_range exception\n";
	}
}

int main()
{
	Vector vec(5);
	f(vec);
}

