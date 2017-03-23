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
#include <typeinfo>
using namespace std;
void g()
{
	cout << "-- g() --\n";

	cout << a << '\n';
}

// add main
void print_file1();
void print_file2()
{
	cout << "-- print_file2() --\n";

	cout << "typeid(T) = " << typeid(T).name() << endl;
	cout << "x = " << x << '\n';
	cout << "c2 = " << c2 << '\n';
}

int main()
{
	print_file1();
	print_file2();

	g();
}
