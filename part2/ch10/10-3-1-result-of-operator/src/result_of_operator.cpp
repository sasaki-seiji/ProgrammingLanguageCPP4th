/*
 * calculate_result.cpp
 *
 *  Created on: 2016/04/25
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void f(int x, int y)
{
	int j = x = y;
	int* p = &++x;
	//int* q = &(x++);
		// lvalue required as unary '&' operand
	int* p2 = &(x>y?x:y);
	//int& r = (x<y)?x:1;
		// invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'

	cout << "j == " << j << '\n';
	cout << "p == " << p << '\n';
	cout << "p2 == " << p2 << '\n';
}

void f()
{
	int i = 1;
	while (0 < i) ++i;
	cout << "i has become negative!" << i << '\n';
}

int main()
{
	f(1, 2);
	f();
}

