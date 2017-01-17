/*
 * atomic_flag.cpp
 *
 *  Created on: 2017/01/17
 *      Author: sasaki
 */


#include <thread>
#include <iostream>
#include "spin_mutex.h"
using namespace std;

spin_mutex spin;

void print_number(int n)
{
	spin.lock();
	cout << "thread#" << n << endl;
	spin.unlock();
}

int main()
{
	const int nthread = 20;
	thread threads[nthread];

	for (int i = 0; i < nthread; ++i)
		threads[i] = thread(print_number, i+1);

	for (int i = 0; i < nthread; ++i)
		threads[i].join();

	return 0;
}
