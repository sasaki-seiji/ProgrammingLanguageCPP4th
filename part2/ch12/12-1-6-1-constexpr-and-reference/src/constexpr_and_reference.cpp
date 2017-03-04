/*
 * constexpr_and_reference.cpp
 *
 *  Created on: 2016/05/05
 *      Author: sasaki
 */

#include <complex>
#include <iostream>
using namespace std;

constexpr int ftbl[] = { 0, 1, 1, 2, 3, 5, 8, 13 };

constexpr int fib(int n)
{
	return (n<sizeof(ftbl)/sizeof(*ftbl)) ? ftbl[n] : fib(n-1)+fib(n-1);
}


constexpr complex<double> zd {2.0}; // 2017.03.05 add
constexpr complex<float> z {zd};

constexpr const int* addr(const int& r) { return &r; }

static const int x = 5;
constexpr const int* p1 = addr(x);
constexpr int xx = *p1;

static int y;
constexpr const int* p2 = addr(y);
//constexpr int yy = *p2;
	// error: the value of 'y' is not usable in a constant expression

//constexpr const int* tp = addr(5);
	// error: '&<anonymous>' is not a constant expression

int main()
{
	cout << "fib(6) = " << fib(6) << '\n';
	cout << "fib(10) = " << fib(10) << '\n';

	cout << "z = " << z << '\n';

	cout << "p1 = " << p1 << ", xx = " << xx << '\n';
	cout << "p2 = " << p2 << '\n';
}

