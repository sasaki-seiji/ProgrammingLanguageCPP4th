/*
 * new_default_value.cpp
 *
 *  Created on: 2017/02/25
 *      Author: sasaki
 */

#include <complex>
#include <iostream>
using namespace std;

int main()
{
	auto pc = new complex<double>;
	auto pi = new int;

	cout << "*pc = " << *pc << endl;
	cout << "*pi = " << *pi << endl;

	auto pc2 = new complex<double>{};
	auto pi2 = new int{};

	cout << "*pc2 = " << *pc2 << endl;
	cout << "*pi2 = " << *pi2 << endl;
}
