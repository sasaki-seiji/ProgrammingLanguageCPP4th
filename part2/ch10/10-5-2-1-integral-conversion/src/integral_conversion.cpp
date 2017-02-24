/*
 * integral_conversion.cpp
 *
 *  Created on: 2016/04/29
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

unsigned char uc = 1023;
	// warning: large integer implicitly truncated to unsigned type [-Woverflow]

signed char sc = 1023;
	// warning: overflow in implicit constant conversion [-Woverflow]

int main()
{
	cout << "int{uc}: " << int{uc} << '\n';
	cout << "int{sc}: " << int{sc} << '\n';
}

