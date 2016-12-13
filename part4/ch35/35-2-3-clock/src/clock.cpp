/*
 * clock.cpp
 *
 *  Created on: 2016/12/13
 *      Author: sasaki
 */


#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void f(long long x)
{
	volatile long long sum = 0;
	for (long long i=0; i<x; ++i)
		sum += i;
}

void test3()
{
	long long x = 1000000000;
	auto t1 = system_clock::now();
	f(x);
	auto t2 = system_clock::now();
	cout << "f(x) took " << duration_cast<milliseconds>(t2-t1).count() << " ms\n";
}

void clock_characteristic()
{
	cout << "min " << system_clock::duration::min().count()
			<< ", max " << system_clock::duration::max().count()
			<< ", " << (treat_as_floating_point<system_clock::duration>::value
						? "FP" : "integral") << '\n';
	cout << (system_clock::is_steady ? "steady\n" : "not stready\n");
}

int main()
{
	test3();
	clock_characteristic();
}
