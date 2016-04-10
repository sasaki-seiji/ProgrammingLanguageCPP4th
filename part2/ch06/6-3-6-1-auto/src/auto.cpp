/*
 * auto.cpp
 *
 *  Created on: 2016/04/10
 *      Author: sasaki
 */

#include <vector>
#include <complex>
#include <iostream>
using namespace std;

int a1 = 123;
char a2 = 123;
auto a3 = 123;

template<typename T> void f1(vector<T>& arg)
{
	for (typename vector<T>::iterator p = arg.begin(); p!=arg.end(); ++p)
		*p = 7;
	for (auto p = arg.begin(); p!=arg.end(); ++p)
		*p = 7;
}

void f(complex<double> d)
{
	//auto max = d+7;
		// no match for 'operator+' (operand types are 'std::complex<double>' and 'int')
	auto max = d+7.0;

	//double min = d-9;
		// no match for 'operator-' (operand types are 'std::complex<double>' and 'int')
	//double min = d-9.0;
		// cannot convert 'std::complex<double>' to 'double' in initialization
}

void f(vector<int>& v)
{
	int sum = 0;
	for (const auto& x : v)
		sum += x ;
	cout << "sum = " << sum << '\n';
}

void g(int& v)
{
	auto x = v;
	auto& y = v;

	y = 10;
	x = 20;
}

template<typename C>
void print(const C& c, ostream& os)
{
	for (const auto& x : c)
		os << x << '\n';
}

int main()
{
	vector<int> v { 1, 2, 3, 4 };
	print(v, cout);
	f1(v);
	print(v, cout);

	f({1, 1});

	f(v);

	int i = 100;
	g(i);
	cout << "i = " << i << '\n';
}


