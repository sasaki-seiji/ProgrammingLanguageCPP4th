/*
 * uniform_random_number.cpp
 *
 *  Created on: 2017/01/14
 *      Author: sasaki
 */

#include <random>
#include <functional>
#include <iostream>
using namespace std;

class Rand_int {
public:
	Rand_int(int lo, int hi) : p{lo,hi} { }
	int operator()() const { return r(); }
private:
	uniform_int_distribution<>::param_type p;
	//auto r = bind(uniform_int_distribution<>{p},default_random_engine{});
		// error: non-static data member declared ‘auto’
	function<int()> r = bind(uniform_int_distribution<>{p},default_random_engine{});
};

class Rand_double {
public:
	Rand_double(double low, double high)
		:r(bind(uniform_real_distribution<>(low,high),default_random_engine())) { }
	double operator()() const { return r(); }
private:
	function<double()> r;
};
void test()
{
	Rand_int ri {10, 20};
	Rand_double rd {0, 0.5};

	for (int i=0; i<100; ++i)
		cout << ri() << ' ';
	cout << endl;
	for (int i=0; i<100; ++i)
		cout << rd() << ' ';
	cout << endl;
}

int main()
{
	test();
}
