/*
 * mutex.cpp
 *
 *  Created on: 2017/01/21
 *      Author: sasaki
 */

#include <thread>
#include <mutex>
#include <iostream>
using namespace std;

mutex cout_mutex;

template<typename Arg1, typename Arg2, typename Arg3>
void write(Arg1 a1, Arg2 a2={}, Arg3 a3={})
{
	thread::id name = this_thread::get_id();
	cout_mutex.lock();
	cout << "From thread " << name << " : " << a1 << " : " << a2 << " : " << a3 << endl;
	cout_mutex.unlock();
}

void run(int num)
{
	const int count = 100;
	for (int i=0; i<count; ++i)
		write(num, i, "writing");
}

int main()
{
	const int nthread = 4;
	thread threads[nthread];

	for (int i=0; i<nthread; ++i)
		threads[i] = thread(run, i);

	for (int i=0; i<nthread; ++i)
		threads[i].join();

	return 0;
}
