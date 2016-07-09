/*
 * file2.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */


using T = double;
const int x = 8;
constexpr T c2 = x+9;

extern const int a;

#include <iostream>
using namespace std;
void g()
{
	cout << a << '\n';
}

// add main
int main()
{
	cout << "x : " << x << '\n';
	cout << "c2 : " << c2 << '\n';
	g();
}
