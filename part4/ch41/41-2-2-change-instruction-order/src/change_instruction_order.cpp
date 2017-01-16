/*
 * change_instruction_order.cpp
 *
 *  Created on: 2017/01/16
 *      Author: sasaki
 */


#include <thread>
#include <chrono>
#include <iostream>
using namespace std;

extern int x;
extern bool x_init;
void init();

void f2()
{
	int y;
	while (!x_init)
		this_thread::sleep_for(chrono::milliseconds{10});
	y = x;
	cout << "f2() done\n";
}

int main()
{
	thread t1 {init};
	thread t2 {f2};
	t1.join();
	t2.join();
}
