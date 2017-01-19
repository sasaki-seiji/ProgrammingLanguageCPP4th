/*
 * construct_thread.cpp
 *
 *  Created on: 2017/01/19
 *      Author: sasaki
 */


#include <thread>
#include <iostream>
using namespace std;

void f0();
void f1(int);

int main()
{
	thread t1 {f0};
	//thread t2 {f0,1};
	//thread t3 {f1};
	thread t4 {f1,1};
	//thread t5 {f1,1,2};
	//thread t6 {f1,"I'm being silly"};

	t1.join();
	t4.join();
}

void f0()
{
	cout << "f0()\n";
	this_thread::sleep_for(chrono::seconds{2});
}

void f1(int i)
{
	cout << "f1(" << i << ")\n";
	this_thread::sleep_for(chrono::seconds{2});
}
