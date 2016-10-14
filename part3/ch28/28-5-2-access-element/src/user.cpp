/*
 * user.cpp
 *
 *  Created on: 2016/10/14
 *      Author: sasaki
 */


#include "Tuple.h"
#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	Tuple<double, int, char> x {1.1, 42, 'a'};
	cout << "{"
			<< get<0>(x) << ", "
			<< get<1>(x) << ", "
			<< get<2>(x) << "}\n";
	auto xx = get<0>(x);
	cout << "typeid(xx).name(): " << typeid(xx).name() << '\n';
}
