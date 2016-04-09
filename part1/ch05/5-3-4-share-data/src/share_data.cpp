/*
 * share_data.cpp
 *
 *  Created on: 2016/04/03
 *      Author: sasaki
 */

#include <mutex>
using std::mutex;
using std::unique_lock;
using std::defer_lock;

#include <thread>
using std::thread;

#include <iostream>
using std::cout;

mutex m;
int sh;

void f()
{
	unique_lock<mutex> lck {m};
	sh += 7;
}

mutex m1, m2, m3;
int sh1, sh2, sh3;

void f2()
{
	unique_lock<mutex> lck1 {m1, defer_lock};
	unique_lock<mutex> lck2 {m2, defer_lock};
	unique_lock<mutex> lck3 {m3, defer_lock};

	lock(lck1, lck2, lck3);

	sh1 += 1; sh2 += 2; sh3 += 3;
}

int main()
{
	thread t1 {f};
	thread t2 {f};

	t1.join();
	t2.join();

	cout << "finally, sh becomes " << sh << '\n';

	thread t3 {f2};
	thread t4 {f2};

	t3.join();
	t4.join();

	cout << "sh1: " << sh1 << ", sh2: " << sh2 << ", sh3: " << sh3 << '\n';
}

