/*
 * destruct_thread.cpp
 *
 *  Created on: 2017/01/19
 *      Author: sasaki
 */


#include <thread>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void output(steady_clock::time_point tp)
{
	cout << tp.time_since_epoch().count() << endl;
}

void heartbeat()
{
	while(true) {
		output(steady_clock::now());
		this_thread::sleep_for(chrono::seconds{1});
	}
}

void run()
{
	thread t {heartbeat};
}

int main()
{
	run();
}
