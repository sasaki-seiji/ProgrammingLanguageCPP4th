/*
 * float_and_integral_conversion.cpp
 *
 *  Created on: 2016/04/29
 *      Author: sasaki
 */

#include <exception>
#include <iostream>
using namespace std;

int i = 2.7;
char b = 2000.7;
	// overflow in implicit constant conversion [-Woverflow]

int i2 = float(1234567890);

char checked_cast(int i)
{
	char c = i;
	if (i != c) throw std::runtime_error{"int-to-char check failed"};
	return c;
}
void my_code(int i)
{
	char c = checked_cast(i);
	cout << "int{c}: " << int{c} << '\n';
}


int main()
{
	cout << "i: " << i << '\n';
	cout << "int{b}: " << int{b} << '\n';
	cout << "i2: " << i2 << '\n';

	try {
		my_code(100);
		my_code(1000);
	}
	catch (std::exception& e) {
		cout << e.what() << '\n';
	}
}

