/*
 * construct_from_initializer_list.cpp
 *
 *  Created on: 2016/05/04
 *      Author: sasaki
 */

#include <cmath>
#include <limits>
#include <complex>
#include <iostream>
using namespace std;

auto d1 = double{2};
double d2 {double{2}/4};

void f(int i) { cout << "f(int:" << i << ")\n"; }
void f(double d) { cout << "f(double:" << d << ")\n"; }

void g(int i, double d)
{
	cout << "-- g(int:" << i << ",double:" << d << ") --\n";

	f(i);
	f(double{i});
		// warning: narrowing conversion of 'i' from 'int' to 'double' inside { } [-Wnarrowing]
	f(d);
	f(int{d});
		// warning: narrowing conversion of 'd' from 'double' to 'int' inside { } [-Wnarrowing]
	f(static_cast<int>(d));
	f(round(d));
	f(static_cast<int>(lround(d)));
}

//static_assert(sizeof(int)==sizeof(double), "unexpected sizes");
int x = numeric_limits<int>::max();
double d = x;
int y = d;


void g2(char* p)
{
	//int x = int{p};
		// invalid conversion from 'char*' to 'int' [-fpermissive]

	using Pint = int*;
	//int* p2 = Pint{p};
		// cannot convert 'char*' to 'Pint {aka int*}' in initialization
}

template<typename T>
void f2(const T& x)
{
	cout << "f2(" << x << ")\n";
}

void g3()
{
	cout << "-- g3() --\n";

	f2(int{});
	f2(complex<double>{});
}

int main()
{
	cout << "d1 = " << d1 << '\n';
	cout << "d2 = " << d2 << '\n';

	g(10, 5.5);

	cout << "x = " << x << '\n';
	cout << "y = " << y << '\n';

	g3();
}

