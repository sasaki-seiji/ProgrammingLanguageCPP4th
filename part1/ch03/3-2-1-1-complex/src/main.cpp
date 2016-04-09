/*
 * main.cpp
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */

#include <iostream>
#include "complex.h"

void f(complex z)
{
	complex a {2.3};
	complex b {1/a};
	complex c {a + z*complex{1, 2.3}};

	if( c != b ) {
		c = -(b/a) + 2 * b;
	}

	// 2016.03.20 add
	std::cout << "a={" << a.real() << ", " << a.imag() << "}\n";
	std::cout << "b={" << b.real() << ", " << b.imag() << "}\n";
	std::cout << "c={" << c.real() << ", " << c.imag() << "}\n";

}

// 2016.03.20 add
int main()
{
	complex z{0, 1};

	std::cout << "z={" << z.real() << ", " << z.imag() << "}\n";
	f(z);
}
