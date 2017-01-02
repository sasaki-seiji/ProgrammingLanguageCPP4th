/*
 * format_number.cpp
 *
 *  Created on: 2017/01/02
 *      Author: sasaki
 */


#include <locale>
#include <iostream>
using namespace std;

class My_punct : public numpunct<char> {
public:
	explicit My_punct(size_t r = 0) : numpunct<char>(r) { }
protected:
	char do_decimal_point() const override { return ','; }
	char do_thousands_sep() const override { return '_'; }
	string do_grouping() const override { return "\003"; }
};

void f()
{
	cout << "style A: " << 12345678
			<< " *** " << 1234567.8
			<< " *** " << fixed << 1234567.8 << '\n';
	cout << defaultfloat;
	locale loc(locale(),new My_punct);
	cout.imbue(loc);
	cout << "style B: " << 12345678
			<< " *** " << 1234567.8
			<< " *** " << fixed << 1234567.8 << '\n';
}

int main()
{
	f();
}

