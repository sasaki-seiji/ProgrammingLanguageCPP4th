/*
 * detach.cpp
 *
 *  Created on: 2017/01/20
 *      Author: sasaki
 */

#include <thread>
#include "heartbeat.h"

using namespace std;
using namespace std::chrono;

void run2()
{
	thread t {heartbeat};
	t.detach();
}

int main()
{
	run2();
	this_thread::sleep_for(seconds{10});
}

