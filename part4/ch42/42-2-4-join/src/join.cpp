/*
 * join.cpp
 *
 *  Created on: 2017/01/20
 *      Author: sasaki
 */


#include <thread>
#include <iostream>
using namespace std;
using namespace std::chrono;

void output(const char* mes)
{
	cout << "message: " << mes << endl;
}

void tick(int n)
{
	for (int i=0; i!=n; ++i) {
		this_thread::sleep_for(seconds{1});
		output("Alive!");
	}
}

int main()
{
	thread timer {tick,10};
	timer.join();
}
