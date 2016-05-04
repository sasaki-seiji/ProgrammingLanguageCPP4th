/*
 * conditional_expression.cpp
 *
 *  Created on: 2016/04/29
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

int max1(int a, int b)
{
	int max;
	if (a <= b)
		max = b;
	else
		max = a;
	return max;
}

int max2(int a, int b) { return (a<=b) ? b : a; }

void fct(int *p)
{
	int i = (p) ? *p : throw std::runtime_error{"unexpected nullptr"};
	cout << "i: " << i << '\n';
}

int main()
{
	cout << "max1(3,4): " << max1(3,4) << '\n';
	cout << "max2(3,4): " << max2(3,4) << '\n';

	int	x = 1;
	try {
		fct(&x);
		fct(0);
	}
	catch (std::runtime_error& e) {
		cout << e.what() << '\n';
	}
}


