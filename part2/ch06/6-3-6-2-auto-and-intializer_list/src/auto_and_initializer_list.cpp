/*
 * auto_and_initializer_list.cpp
 *
 *  Created on: 2016/04/10
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

using T = int;
char f() { return 'a' ; }

char v1 = 12345;
	// overflow in implicit constant conversion [-Woverflow]
int v2 = 'c';
T v3 = f();

//char v1i { 12345 };
	//narrowing conversion of '12345' from 'int' to 'char' inside { } [-Wnarrowing]
int v2i {'c'};
T v3i {f()};

auto v1a = 12345;
auto v2a = 'c';
auto v3a = f();

auto v1ai {12345};
auto v2ai {'c'};
auto v3ai {f()};

int main()
{
	cout << "v1 = " << v1 << '\n';
	cout << "v2 = " << v2 << '\n';
	cout << "v3 = " << v3 << '\n';

	cout << "v1a = " << v1a << '\n';
	cout << "v2a = " << v2a << '\n';
	cout << "v3a = " << v3a << '\n';

	cout << "v1ai = " << v1ai << '\n';
	cout << "v2ai = " << v2ai << '\n';
	cout << "v3ai = " << v3ai << '\n';
}
