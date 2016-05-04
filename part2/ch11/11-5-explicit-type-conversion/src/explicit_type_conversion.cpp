/*
 * explicit_type_conversion.cpp
 *
 *  Created on: 2016/05/03
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

template<typename Target, typename Source>
Target narrow_cast(Source v)
{
	auto r = static_cast<Target>(v);
	if (static_cast<Source>(r) != v)
		throw runtime_error("narrow_cast<> failed");
	return r;
}

void test(double d, int i, char* p)
{
	try {
		auto c1 = narrow_cast<char>(64);
		cout << "int{c1}: " << int{c1} << '\n';
	}
	catch (runtime_error& e) {
		cerr << "narrow_cast<char>(64): " << e.what() << '\n';
	}

	try {
		auto c2 = narrow_cast<char>(-64);
		cout << "int{c2}: " << int{c2} << '\n';
	}
	catch (runtime_error& e) {
		cerr << "narrow_cast<char>(-64): " << e.what() << '\n';
	}

	try {
		auto c3 = narrow_cast<char>(264);
		cout << "int{c3}: " << c3 << '\n';
	}
	catch (runtime_error& e) {
		cerr << "narrow_cast<char>(264): " << e.what() << '\n';
	}

	try {
		auto d1 = narrow_cast<double>(1/3.0F);
		cout << "d1: " << d1 << '\n';
	}
	catch (runtime_error& e) {
		cerr << "narrow_cast<double>(1/3.0F): " << e.what() << '\n';
	}

	try {
		auto f1 = narrow_cast<float>(1/3.0);
		cout << "f1: " << f1 << '\n';
	}
	catch (runtime_error& e) {
		cerr << "narrow_cast<float>(1/3.0): " << e.what() << '\n';
	}

	try {
		auto c4 = narrow_cast<char>(i);
		cout << "c4: " << c4 << '\n';
	}
	catch (runtime_error& e) {
		cerr << "narrow_cast<char>(i): " << e.what() << '\n';
	}

	try {
		auto f2 = narrow_cast<float>(d);
		cout << "f2: " << f2 << '\n';
	}
	catch (runtime_error& e) {
		cerr << "narrow_cast<float>(d): " << e.what() << '\n';
	}


	//auto p1 = narrow_cast<char*>(i);
		// invalid static_cast from type 'char*' to type 'int'
	//auto i1 = narrow_cast<int>(p);
		// invalid static_cast from type 'int' to type 'char*'

	try {
		auto d2 = narrow_cast<double>(i);
		cout << "d2: " << d2 << '\n';
	}
	catch (runtime_error& e) {
		cerr << "narrow_cast<double>(i): " << e.what() << '\n';
	}

	try {
		auto i2 = narrow_cast<int>(d);
		cout << "i2: " << i2 << '\n';
	}
	catch (runtime_error& e) {
		cerr << "narrow_cast<int>(d): " << e.what() << '\n';
	}
}

int main()
{
	char	c;
	test(1.1e-300, 1000, &c);
}

