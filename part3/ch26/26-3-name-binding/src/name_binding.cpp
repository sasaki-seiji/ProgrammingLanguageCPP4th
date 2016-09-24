/*
 * name_binding.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

bool tracing;

template<typename T>
T sum(std::vector<T>& v)
{
	T t {};
	if (tracing)
		cerr << "sum(" << &v << ")\n";
	//for (int i = 0; i!=v.size(); ++i)
	for (size_t i = 0; i!=v.size(); ++i)
		t = t + v[i];
	return t;
}

#include "quad.h"

void f(std::vector<Quad>& v)
{
	tracing = false;
	Quad c1 = sum(v);
	cout << "sum: " << c1 << '\n';

	tracing = true;
	Quad c2 = sum(v);
	cout << "sum: " << c2 << '\n';
}

// add main

int main()
{
	std::vector<Quad> vq { 1.1, 2.2, 3.3, 4.4, 5.5 };
	f(vq);
}
