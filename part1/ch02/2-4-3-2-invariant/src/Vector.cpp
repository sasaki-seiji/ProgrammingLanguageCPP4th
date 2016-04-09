/*
 * Vector.cpp
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */

#include <stdexcept>
using namespace std;

#include "Vector.h"

Vector::Vector(int s)
{
	//if( s < 0 ) throw length_error{};
	if( s < 0 ) throw length_error{"Vector::Vector"};
		// no matching function for call to 'std::length_error::length_error(<brace-enclosed initializer list>)'

	elem = new double[s];
	sz = s;
}

double& Vector::operator[](int i)
{
	if( i < 0 || size() <= i ) throw out_of_range("Vector::operator[]");
	return elem[i];
}

int Vector::size()
{
	return sz;
}
