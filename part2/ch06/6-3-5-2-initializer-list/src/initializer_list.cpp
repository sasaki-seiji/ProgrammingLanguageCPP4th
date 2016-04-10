/*
 * initializer_list.cpp
 *
 *  Created on: 2016/04/10
 *      Author: sasaki
 */

#include <complex>
#include <vector>
#include <iostream>
using namespace std;

int a[] = { 1, 2 };
struct S { int x; string s; };
S s = { 1, "Helios" };
const double pi = 3.14159;
complex<double> z = { 0, pi };
vector<double> v = { 0.0, 1.1, 2.2, 3.3 };

complex<double> z1(0, pi);
complex<double> f1();	// function declaration
vector<double> v1(10, 3.3);

complex<double> z2 {1, 2};
complex<double> f2 { };

//auto x1 {1, 2, 3, 4};
// direct-list-initialization of 'auto' requires exactly one element [-fpermissive]
//auto x2 {1.0, 2.25, 3.5};
// direct-list-initialization of 'auto' requires exactly one element [-fpermissive]
//auto x3 {1.0, 2};
// direct-list-initialization of 'auto' requires exactly one element [-fpermissive]
// unable to deduce 'std::initializer_list<_Tp>' from '{1.0e+0, 2}'

int main()
{
	cout << "z = " << z << '\n';
	cout << "v.size() = " << v.size() << '\n';

	cout << "z1 = " << z1 << '\n';
	cout << "v1.size() = " << v1.size() << '\n';
	cout << "z2 = " << z2 << '\n';
	cout << "f2 = " << f2 << '\n';
}
