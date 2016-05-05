/*
 * constexpr_function.cpp
 *
 *  Created on: 2016/05/05
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

constexpr int fac(int n)
{
	return (n>1) ? n*fac(n-1) : 1;
}

constexpr int f9 = fac(9);

void f(int n)
{
	int f5 = fac(5);
	int fn = fac(n);

	constexpr int f6 = fac(6);
	//constexpr int fnn = fac(n);
		// 'n' is not a constant expression

	char a[fac(4)];
	char a2[fac(n)];

	cout << "f5: " << f5 << '\n';
	cout << "fn: " << fn << '\n';
	cout << "f6: " << f6 << '\n';

	cout << "sizeof(a): " << sizeof(a) << '\n';
	cout << "sizeof(a2): " << sizeof(a2) << '\n';
}

int glob;

#if 0
constexpr void bad1(int a)
	// invalid return type 'void' of constexpr function 'constexpr void bad1(int)'
{
	glob = a;
}
#endif

#if 0
constexpr int bad2(int a)
{
	if (a>=0) return a; else return -a;
}
	// body of constexpr function 'constexpr int bad2(int)' not a return-statement
#endif

#if 0
constexpr int bad3(int a)
{
	int sum = 0;
	for (int i=0; i<a; ++i) sum += fac(i);
	return sum;
}
	// body of constexpr function 'constexpr int bad3(int)' not a return-statement
#endif

int main()
{
	cout << "f9: " << fac(9) << '\n';
	f(7);
}

