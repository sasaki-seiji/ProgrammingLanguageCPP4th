/*
 * join.cpp
 *
 *  Created on: 2017/01/20
 *      Author: sasaki
 */

#include <thread>
#include "tick.h"
using namespace std;

int main()
{
	thread timer {tick,10};
	timer.join();
}
