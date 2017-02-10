/*
 * omit_initializer.cpp
 *
 *  Created on: 2016/04/10
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

int a;
double d;

void f()
{
	cout << "-- f() --\n";

	int x;
	char buf[1024];
	int* p {new int};
	char *q {new char[1024]};

	string s;
	vector<char> v;
	string* ps {new string};

	cout << "x = " << x << '\n';
		// warning: ‘x’ may be used uninitialized in this function [-Wmaybe-uninitialized]
	cout << "int{buf[1000]} = " << int{buf[1000]} << '\n';
	cout << "*p = " << *p << '\n';
	cout << "int{q[1000]} = " << int{q[1000]} << '\n';

	cout << "s = " << s << '\n';
	cout << "v.size() = " << v.size() << '\n';
	cout << "*ps = " << *ps << '\n';
}

void ff()
{
	cout << "-- ff() --\n";

	int x { };
	char buf[1024] { };
	int* p {new int{10}};
	char* q {new char[1024]{ }};

	cout << "x = " << x << '\n';
	cout << "int{buf[1000]} = " << int{buf[1000]} << '\n';
	cout << "*p = " << *p << '\n';
	cout << "int{q[1000]} = " << int{q[1000]} << '\n';
}

int main()
{
	cout << "::a = " << ::a << '\n';
	cout << "::d = " << ::d << '\n';

	f();
	ff();
}
