/*
 * double_checked_locking.cpp
 *
 *  Created on: 2017/01/17
 *      Author: sasaki
 */


#include <atomic>
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

typedef long long X;

X x;
mutex lx;
atomic<bool> x_init {false};

X y;

void some_code()
{
	if (!x_init) {
		lx.lock();
		if (!x_init) {
			x = 12345678901234567;
			x_init = true;
		}
		lx.unlock();
	}
	y = x - 100000;
}

int main()
{
	const int nthread = 10;
	thread threads[nthread];

	for (int i=0; i<nthread; ++i)
		threads[i] = thread(some_code);

	for (int i=0; i<nthread; ++i)
		threads[i].join();

	cout << "x=" << x << ", y=" << y << endl;
}
