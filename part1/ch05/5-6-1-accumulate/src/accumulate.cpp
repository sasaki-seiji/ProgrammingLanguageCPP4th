/*
 * accumulate.cpp
 *
 *  Created on: 2016/04/07
 *      Author: sasaki
 */

#include <list>
#include <numeric>
#include <iostream>
using namespace std;

void f()
{
	list<double> lst {1, 2, 3, 4, 5, 9999.99999};
	auto s = accumulate(lst.begin(), lst.end(), 0.0);
	cout << s << '\n';
}

int main()
{
	f();
}
