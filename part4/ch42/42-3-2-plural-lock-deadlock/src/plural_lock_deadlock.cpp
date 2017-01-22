/*
 * plural_lock_deadlock.cpp
 *
 *  Created on: 2017/01/22
 *      Author: sasaki
 */


#include <thread>
#include <mutex>
#include <iostream>
using namespace std;

mutex mtx1;
mutex mtx2;

void task(mutex& m1, mutex& m2)
{
	unique_lock<mutex> lck1 {m1};
	unique_lock<mutex> lck2 {m2};

	// use resource
}

void f(mutex& m1, mutex&m2)
{
	const int count = 10000;
	const int report = 100;
	thread::id id = this_thread::get_id();

	cout << "start f(): " << id << endl;

	for (int i=1; i<=count; ++i) {
		task(m1,m2);
		if (i % report == 0)
			cout << i << " done: " << id << endl;
	}

	cout << "finish f(): " << id << endl;
}

int main()
{
	thread t1 {f,ref(mtx1),ref(mtx2)};
	thread t2 {f,ref(mtx2),ref(mtx1)};

	t1.join();
	t2.join();
}
