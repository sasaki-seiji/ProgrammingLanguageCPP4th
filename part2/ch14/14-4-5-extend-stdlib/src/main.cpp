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
using namespace std;

template<typename T>
void print(const vector<T>& v)
{
	for (auto& x : v)
		cout << x << ' ';
	cout << '\n';
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
