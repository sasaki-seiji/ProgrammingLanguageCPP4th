/*
 * chrono.cpp
 *
 *  Created on: 2016/12/13
 *      Author: sasaki
 */


#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

long long delay(long long count)
{
	volatile long long sum = 0;
	for (long long i = 0 ; i < count; ++i)
		sum += i;
	return sum;
}

int main()
{
	auto t = steady_clock::now();
	delay(100000000);
	auto d = steady_clock::now()-t;
	cout << "something took "
			<< duration_cast<milliseconds>(d).count() << "ms";
}
