/*
 * partial_sum_and_adjacent_difference.cpp
 *
 *  Created on: 2017/01/14
 *      Author: sasaki
 */

#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

vector<double> temps {17, 19, 20, 20, 17};

void f()
{
	adjacent_difference(temps.begin(), temps.end(), temps.begin());
}

void f2()
{
	partial_sum(temps.begin(), temps.end(), temps.begin());
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto x : v)
		os << x << ' ';
	return os;
}

int main()
{
	cout << "original temps:      " << temps << endl;
	f();
	cout << "adjacent_difference: " << temps << endl;
	f2();
	cout << "partial_sum:         " << temps << endl;
}

