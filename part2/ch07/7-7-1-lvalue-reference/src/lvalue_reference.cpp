/*
 * lvalue_reference.cpp
 *
 *  Created on: 2016/04/17
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
using namespace std;

void f()
{
	cout << "-- f() --\n";

	int var = 1;
	int& r {var};
	int x = r;

	r = 2;

	cout << "var = " << var << '\n';
	cout << "r = " << r << '\n';
	cout << "x = " << x << '\n';
}

int var = 1;
int& r1 {var};
//int& r2;
	// error: 'r2' declared as reference but not initialized
extern int& r3;	// defined anywhere

void g()
{
	cout << "-- g() --\n";

	int var = 0;
	int& rr {var};
	++rr;
	int* pp = &rr;

	cout << "var = " << var << '\n';
	cout << "rr = " << rr << '\n';
	cout << "pp = " << pp << ", &var = " << &var << '\n';
}

//double& dr = 1;
	// error: invalid initialization of non-const reference of type 'double&' from an rvalue of type 'double'
const double& cdr {1};

void increment(int& aa)
{
	++aa;
}
void f2()
{
	cout << "-- f2() --\n";

	int x = 1;
	increment(x);
	cout << "x = " << x << '\n';
}

int next(int p) { return p+1; }
void g2()
{
	cout << "-- g2() --\n";

	int x = 1;
	increment(x);
	x = next(x);
	cout << "x = " << x << '\n';
}

int main()
{
	cout << "::var = " << ::var << '\n';
	cout << "::r1 = " << ::r1 << '\n';
	cout << "::r3 = " << ::r3 << '\n';

	f();
	g();
	f2();
	g2();
}

int temp = 3;
int& r3 {temp};
