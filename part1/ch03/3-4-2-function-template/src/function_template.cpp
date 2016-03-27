/*
 * function_template.cpp
 *
 *  Created on: 2016/03/27
 *      Author: sasaki
 */

#include <list>
#include <vector>
#include <complex>
#include <iostream>
#include "Vector.h"

template<typename Container, typename Value>
Value sum(const Container& c, Value v)
{
	for (auto x : c)
		v += x;
	return v;
}

void user(Vector<int>& vi, std::list<double>& ld, std::vector<std::complex<double>>& vc)
{
	int x = sum(vi, 0);
	double d = sum(vi, 0.0);
	double dd = sum(ld, 0.0);
	auto z = sum(vc, std::complex<double>{});

	std::cout << "sum(vi, 0) : " << x << '\n';
	std::cout << "sum(vi, 0.0) : " << d << '\n';
	std::cout << "sum(ld, 0.0) : " << dd << '\n';
	std::cout << "sum(vc, std::complex<double>{}) : " << z << '\n';
}

int main()
{
	Vector<int> vi(5);
	for (int i = 0 ; i != 5; ++i) vi[i] = 11;

	std::list<double> ld;
	ld.push_back(1.0); ld.push_back(2.0); ld.push_back(3.0);

	std::vector<std::complex<double>> vc = {{1, 1}, {1, 2}, {1,3}};

	user(vi, ld, vc);
}
