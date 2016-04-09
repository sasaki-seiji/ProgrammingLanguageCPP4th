/*
 * random.cpp
 *
 *  Created on: 2016/04/08
 *      Author: sasaki
 */

#include <random>
#include <functional>
#include <vector>
#include <iostream>
using namespace std;


void f()
{
	using my_engine = default_random_engine;
	using my_distribution = uniform_int_distribution<>;

	my_engine re { };
	my_distribution one_to_six {1, 6};
	auto die = bind(one_to_six, re);

	int x = die();
	cout << "x = " << x << '\n';
}

void g()
{
	auto die = bind(uniform_int_distribution<>{1,6}, default_random_engine{});
	int x = die();
	cout << "x = " << x << '\n';
}

class Rand_int {
public:
	Rand_int(int low, int high) :dist {low, high} { }
	int operator()() { return dist(re); }
private:
	default_random_engine re;
	uniform_int_distribution<> dist;
};

void h()
{
	Rand_int rnd {0, 4};

	vector<int> histogram(5);
	for (int i = 0; i != 200; ++i)
		++histogram[rnd()];

	for (int i = 0; i != histogram.size(); ++i) {
		cout << i << '\t';
		for (int j = 0; j != histogram[i]; ++j) cout << '*';
		cout << '\n';
	}
}

int main()
{
	f();
	g();
	h();
}
