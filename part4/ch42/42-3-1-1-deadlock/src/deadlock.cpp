/*
 * deadlock.cpp
 *
 *  Created on: 2017/01/21
 *      Author: sasaki
 */


#include <thread>
#include <mutex>
#include <iostream>
using namespace std;


mutex cout_mutex;

void write()
{
	cout_mutex.lock();
	cout << endl;
	cout_mutex.unlock();
}

template<typename Arg, typename... Args>
void write(Arg a, Args... tail)
{
	cout_mutex.lock();
	cout << a;
	write(tail...);
	cout_mutex.unlock();
}

void f()
{
	write(this_thread::get_id(), "Hello,", "World!");
}

int main()
{
	thread t1{f};
	thread t2{f};

	t1.join();
	t2.join();
}
