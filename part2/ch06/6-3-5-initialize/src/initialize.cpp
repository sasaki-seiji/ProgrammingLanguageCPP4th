/*
 * initialize.cpp
 *
 *  Created on: 2016/04/10
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
using namespace std;

void f(double val, int val2)
{
	int x2 = val;
	char c2 = val2;

	int x3 {val};
	// narrowing conversion of 'val' from 'double' to 'int' inside { } [-Wnarrowing]

	char c3 {val2};
	// narrowing conversion of 'val2' from 'int' to 'char' inside { } [-Wnarrowing]

	char c4 {24};
	//char c5 {264};
	// narrowing conversion of '264' from 'int' to 'char' inside { } [-Wnarrowing]

	//int x4 {2.0};
	// narrowing conversion of '2.0e+0' from 'double' to 'int' inside { } [-Wnarrowing]

	cout << "x2 = " << x2 << '\n';
	cout << "c2 = " << c2 << ", int{c2} = " << int{c2} << '\n';
	cout << "x3 = " << x3 << '\n';
	cout << "c3 = " << c3 << ", int{c3} = " << int{c3} << '\n';
	cout << "c4 = " << c4 << ", int{c4} = " << int{c4} << '\n';
}

int main()
{
	f(7.9, 1025);

	auto z1 {99};
	auto z2 = 99;

	cout << "z1 = " << z1 << ", z2 = " << z2 << '\n';

	vector<int> v1 {99};
	vector<int> v2(99);
	cout << "v1.size() = " << v1.size() << ", v2.size() = " << v2.size() << '\n';

	vector<string> vs1{"hello"};
	//vector<string> vs2("hello");
	// no matching function for call to 'std::vector<std::__cxx11::basic_string<char> >::vector(const char [6])'

	int x4 {};
	double d4 {};
	char* p {};
	vector<int> v4 {};
	string s4 {};

	cout << "x4 = " << x4 << '\n';
	cout << "d4 = " << d4 << '\n';
	cout << "p == nullptr ? " << ( p == nullptr ) << '\n';
	cout << "v4.size() = " << v4.size() << '\n';
	cout << "s4.size() = " << s4.size() << '\n';
}
