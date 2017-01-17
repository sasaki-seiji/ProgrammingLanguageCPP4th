/*
 * compare_exchange_weak.cpp
 *
 *  Created on: 2017/01/17
 *      Author: sasaki
 */


#include <atomic>
#include <thread>
#include <iostream>
using namespace std;

//atomic<int> val = 0;
	// error: use of deleted function ‘std::atomic<int>::atomic(const std::atomic<int>&)’
atomic<int> val {0};

void test(int count, int(*fct)(int))
{
	for (int i=0; i < count; ++i) {
		int expected = val.load();
		int next;
		do {
			next = fct(expected);
		} while (!val.compare_exchange_weak(expected, next));
	}
}

int inc2(int val)
{
	return val+2;
}

int dec1(int val)
{
	return val-1;
}

int main()
{
	const int count = 10000000;
	thread th1 = thread(test, count, inc2);
	thread th2 = thread(test, count, dec1);

	th1.join();
	th2.join();

	cout << "finally val=" << val.load() << endl;
	return 0;
}
