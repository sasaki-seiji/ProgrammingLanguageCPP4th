/*
 * format_state.cpp
 *
 *  Created on: 2016/12/27
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

void test_floatfield()
{
	cout.setf(ios_base::fixed | ios_base::scientific, ios_base::floatfield);
	cout << 1234.5678 << '\n';

	cout.unsetf(ios_base::floatfield);
	cout << 1234.5678 << '\n';
}

void test_precision()
{
	cout.precision(8);
	cout << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456 << '\n';

	cout.precision(4);
	cout << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456 << '\n';
}

void test_width()
{
	cout.width(4);
	cout << 12 << '\n';

	cout.width(4);
	cout.fill('#');
	cout << "ab" << '\n';

	cout.width(4);
	cout << "abcded" << '\n';

	cout.width(4);
	cout.fill('#');
	cout << 12 << ':' << 13 << '\n';
}

int main()
{
	test_floatfield();
	test_precision();
	test_width();
}
