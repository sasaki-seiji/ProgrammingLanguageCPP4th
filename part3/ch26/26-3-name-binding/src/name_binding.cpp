/*
 * name_binding.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#include "sum.h"
#include "quad.h"

#include <vector>
#include <iostream>
using namespace std;

bool tracing;

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
