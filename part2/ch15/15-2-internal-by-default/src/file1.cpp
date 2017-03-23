/*
 * file1.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */

using T = int;
const int x = 7;
constexpr T c2 = x+1;

extern const int a = 77;

// 2017.03.23 add
#include <iostream>
#include <typeinfo>
using namespace std;
void print_file1()
{
	cout << "-- print_file1() --\n";

	cout << "typeid(T) = " << typeid(T).name() << endl;
	cout << "x = " << x << endl;
	cout << "c2 = " << c2 << endl;
}
