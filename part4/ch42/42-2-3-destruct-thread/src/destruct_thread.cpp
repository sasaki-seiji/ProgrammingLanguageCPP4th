/*
 * destruct_thread.cpp
 *
 *  Created on: 2017/01/19
 *      Author: sasaki
 */

#include <thread>
#include "heartbeat.h"
using namespace std;


void run()
{
	thread t {heartbeat};
}

int main()
{
	run();
}
