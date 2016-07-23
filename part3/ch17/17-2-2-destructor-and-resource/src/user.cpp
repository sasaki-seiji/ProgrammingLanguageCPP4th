/*
 * user.cpp
 *
 *  Created on: 2016/07/24
 *      Author: sasaki
 */

#include "Vector.h"

Vector* f(int s)
{
	Vector v1(s);

	return new Vector(s+s);
}

void g(int ss)
{
	Vector* p = f(ss);

	delete p;
}

// add main
int main()
{
	g(100);
}

