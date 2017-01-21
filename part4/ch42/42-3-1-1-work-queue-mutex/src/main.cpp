/*
 * main.cpp
 *
 *  Created on: 2017/01/21
 *      Author: sasaki
 */

#include <thread>
using namespace std;

#include "work_queue.h"

void composer();

int main()
{
	thread c {composer};
	thread w {worker};

	c.join();
	w.join();
}

