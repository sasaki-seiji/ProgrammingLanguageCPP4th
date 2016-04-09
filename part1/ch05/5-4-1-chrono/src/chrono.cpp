/*
 * chrono.cpp
 *
 *  Created on: 2016/04/05
 *      Author: sasaki
 */

#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void do_work()
{
	double sum = 0;
	for (int i = 0; i < 10000000; ++i)
		sum += i;
}

int main()
{
	auto t0 = high_resolution_clock::now();
	do_work();
	auto t1 = high_resolution_clock::now();
	cout << duration_cast<milliseconds>(t1-t0).count() << "msec\n";
}


