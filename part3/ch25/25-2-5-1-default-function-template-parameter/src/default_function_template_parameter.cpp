/*
 * default_function_template_parameter.cpp
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template<typename Target =string, typename Source =string>
Target to(Source arg)
{
	stringstream interpreter;
	Target result;

	if (!(interpreter << arg)
		|| !(interpreter >> result)
		|| !(interpreter >> std::ws).eof())
		throw runtime_error{"to<> failed"};

	return result;
}


auto x1 = to<string,double>(1.2);
auto x2 = to<string>(1.2);
auto x3 = to<>(1.2);
auto x4 = to(1.2);


int main()
{
	cout << "x1: " << x1 << '\n';
	cout << "x2: " << x2 << '\n';
	cout << "x3: " << x3 << '\n';
	cout << "x4: " << x4 << '\n';

	auto d1 = to<double>(10);
	cout << "d1: " << d1 << '\n';

	try {
		auto c1 = to<char>(100);
		cout << "c1: " << c1 << '\n';
	}
	catch( const runtime_error& e) {
		cout << e.what();
	}
}
