/*
 * move_thread.cpp
 *
 *  Created on: 2017/01/20
 *      Author: sasaki
 */

#include <thread>
#include <vector>
#include <iostream>
#include "heartbeat.h"
#include "tick.h"

using namespace std;
using namespace std::chrono;

vector<thread> my_threads;

void run()
{
	thread t {heartbeat};
	my_threads.push_back(move(t));

	my_threads.emplace_back(tick,1000);
}

void monitor()
{
	for (thread& t : my_threads)
		cout << "thread " << t.get_id() << '\n';
}

int main()
{
	run();
	for (;;) {
		this_thread::sleep_for(seconds{5});
		monitor();
	}
}
