/*
 * noexcept_function.cpp
 *
 *  Created on: 2016/05/18
 *      Author: sasaki
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

double compute(double x, size_t sz) noexcept
{
	string s = "Courtney and Anya";
	vector<double> tmp(sz);
	double sum = 0;
	for (auto it = tmp.begin(); it != tmp.end(); ++it) {
		*it = x * x;
		sum += *it;
	}

	return sum;
}

int main()
{
	double res;

	res = compute(12.3, 1000);
	cout << "compute(12.3, 1000): " << res << '\n';

	res = compute(12.3, 1000*1000);
	cout << "compute(12.3, 1000*1000): " << res << '\n';

	res = compute(12.3, 1000*1000*1000);
	cout << "compute(12.3, 1000*1000*1000): " << res << '\n';

#if 0	// raise exception
	res = compute(12.3, 1000*1000*1000*1000);
	cout << "compute(12.3, 1000*1000*1000*1000): " << res << '\n';
#endif
}
