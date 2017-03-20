/*
 * main.cpp
 *
 *  Created on: 2016/05/27
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
#include "Estd.h"

using namespace Estd;

template<typename T>
void print(const std::vector<T>& v)
{
	for (auto& x : v)
		std::cout << x << ' ';
	std::cout << '\n';
}

void f()
{
	std::vector<int> v {7, 3, 9, 4, 0, 1};

	sort(v);
	print(v);

	sort(v, [](int x, int y){ return x>y; });
	print(v);

	sort(v.begin(), v.end());
	print(v);

	sort(v.begin(), v.end(), [](int x, int y){ return x>y; });
	print(v);
}

int main()
{
	f();
}
