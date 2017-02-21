/*
 * operator_priority.cpp
 *
 *  Created on: 2017/02/21
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void test_max(int i, int max)
{
	cout << "-- test_max(int i:" << dec << i << ", int max:" << max << ")\n";

	if (i<=0 || max<i) {
		cout << "i<=0 || max<i" << endl;
	}

	if ( (i<=0) || (max<i) ) {
		cout << "(i<=0) || (max<i)" << endl;
	}

}

void test_mask(int i, int mask)
{
	cout << "-- test_mask(int i:" << hex << i << ", int mask:" << mask << ")\n";

	if (i&mask == 0) {
		// warning: suggest parentheses around comparison in operand of ‘&’ [-Wparentheses]
		cout << "i&mask == 0" << endl;
	}

	if ((i&mask) == 0) {
		cout << "(i&mask) == 0" << endl;
	}

}

void test_range(int x)
{
	cout << "-- test_range(int x:" << dec << x << ")\n";

	if (0 <= x <= 99) {
		// warning: comparison of constant ‘99’ with boolean expression is always true [-Wbool-compare]
		// warning: comparisons like ‘X<=Y<=Z’ do not have their mathematical meaning [-Wparentheses]
		cout << "0 <= x <= 99" << endl;
	}

	if (0 <= x && x <= 99) {
		cout << "0 <= x && x <= 99" << endl;
	}

}

void test_assign(int a)
{
	cout << "-- test_assign(int a:" << a << ")\n";

	if (7 == a) {
		cout << "7 == a" << endl;
	}

	if (a = 7) {
		// warning: suggest parentheses around assignment used as truth value [-Wparentheses]
		cout << "a = 7" << endl;
	}
}

int main()
{
	test_max(10, 10);
	test_max(11, 10);

	test_mask(0xa, 0x5);
	test_range(100);

	test_assign(5);
}


