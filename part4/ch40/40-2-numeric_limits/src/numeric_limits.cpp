/*
 * numeric_limits.cpp
 *
 *  Created on: 2017/01/11
 *      Author: sasaki
 */


#include <limits>
#include <climits>
#include <cfloat>
#include <iostream>

namespace std {

	struct Quad {
		using Value = long double;
		Value v;
	};

	template<>
	class numeric_limits<Quad> {
	public:
		static const bool is_specialized = true;
	};

}

using namespace std;

void f(double d, int i)
{
	char classification[numeric_limits<unsigned char>::max()];

	if (numeric_limits<unsigned char>::digits == numeric_limits<char>::digits) {
		cout << "char is unsigned\n";
	}
	else {
		cout << "char is signed\n";
	}

	if (i < numeric_limits<short>::min() || numeric_limits<short>::max() < i) {
		cout << i << " overflows with short\n";
	}

	if (0<d && d<numeric_limits<double>::epsilon()) {
		cout << d << " is less than epsilon\n";
	}

	if (numeric_limits<Quad>::is_specialized) {
		cout << "numeric_limits<Quad> is specialized\n";
	}
}

void test_climits()
{
	cout << "CHAR_BIT:" << CHAR_BIT << endl;
	cout << "CHAR_MIN:" << CHAR_MIN << endl;
	cout << "CHAR_MAX:" << CHAR_MAX << endl;
	cout << "INT_MIN:" << INT_MIN << endl;
	cout << "LONG_MAX:" << LONG_MAX << endl;

	cout << "FLT_MIN:" << FLT_MIN << endl;
	cout << "FLT_MAX:" << FLT_MAX << endl;
	cout << "FLT_DIG:" << FLT_DIG << endl;
	cout << "DBL_MIN:" << DBL_MIN << endl;
	cout << "DBL_MAX:" << DBL_MAX << endl;
	cout << "DBL_EPSILON:" << DBL_EPSILON << endl;
}

int main()
{
	f(1e-16, 100000);
	test_climits();
}
