/*
 * alternate_expression.cpp
 *
 *  Created on: 2017/02/19
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

int main()
{
	bool x = true, y = false, z = true;
	int x1 = 0xaaaa, x2 = 0xbbbb, x3 = 0xcccc;

	bool b = not (x or y) and z;
	int x4 = compl (x1 bitor x2) bitand x3;

	cout << boolalpha << hex;
	cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
	cout << "x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 << endl;
	cout << "b = " << b << endl;
	cout << "x4 = " << x4 << endl;
}

