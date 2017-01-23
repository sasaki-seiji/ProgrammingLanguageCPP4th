/*
 * simple_timer.cpp
 *
 *  Created on: 2017/01/23
 *      Author: sasaki
 */


#include <thread>
#include <condition_variable>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void simple_timer(int delay)
{
	condition_variable timer;
	mutex mtx;
	auto t0 = steady_clock::now();
	unique_lock<mutex> lck(mtx);
	timer.wait_for(lck,milliseconds{delay});
	auto t1 = steady_clock::now();
	cout << duration_cast<milliseconds>(t1-t0).count() << " milliseconds passed\n";
}

void task()
{
	simple_timer(1);
	simple_timer(10);
	simple_timer(100);
	simple_timer(1000);
}

int main()
{
	thread th{task};
	th.join();
}
