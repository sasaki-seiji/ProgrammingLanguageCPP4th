/*
 * heartbeat.cpp
 *
 *  Created on: 2017/01/20
 *      Author: sasaki
 */


#include <thread>
#include <iostream>
#include "heartbeat.h"
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
