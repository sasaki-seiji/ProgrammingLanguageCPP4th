/*
 * normal_distribution.cpp
 *
 *  Created on: 2017/01/14
 *      Author: sasaki
 */


#include <random>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

map<int, int> dist;

void f()
{
	auto gen = bind(normal_distribution<double>{15,4.0},default_random_engine{});
	for (int i = 0; i<500; ++i)
#if 0
		cout << gen();
#else
		dist[round(gen())]++;
#endif
}

int main()
{
	f();
	for (auto p : dist) {
		cout << setw(3) << p.first << ' ';
		for (int i = 0; i < p.second; ++i)
			cout << '*';
		cout << endl;
	}
}
