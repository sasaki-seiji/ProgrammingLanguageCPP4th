/*
 * type_conversion.cpp
 *
 *  Created on: 2016/03/18
 *      Author: sasaki
 */
// 2016.03.18 add
#include <iostream>

void some_function()
{
	double d = 2.2;
	int i = 7;
	d = d + i;
	i = d * i; // no warning

	// 2016.03.18 add
	std::cout << " d = " << d << ", i = " << i << "\n";
}
int main()
{
	some_function();
}


