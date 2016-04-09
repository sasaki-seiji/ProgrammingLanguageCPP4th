/*
 * invariant.cpp
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */

#include <iostream>
#include <stdexcept>

#include "Vector.h"

void test()
{
	try {
		Vector v(-27);
	}
	catch( std::length_error) { // warning: Catching by reference is recommended 'std::length_error'

		std::cout << "caught length_error exception\n";
	}
	catch( std::bad_alloc ) { // warning: Catching by reference is recommended 'std::bad_alloc'

		std::cout << "caught bad_alloc exception\n";
	}
}

int main()
{
	test();
}
