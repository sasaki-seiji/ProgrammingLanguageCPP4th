/*
 * task_and_thread.cpp
 *
 *  Created on: 2016/04/03
 *      Author: sasaki
 */

#include <thread>
#include <iostream>
using namespace std;

void f();

struct F {
	void operator()();
};

void user()
{
	thread t1 {f};
	thread t2 {F()};

	t1.join();
	t2.join();
}

void f() { cout << "Hello "; }
void F::operator()(){ cout << "Parallel World\n"; }

int main()
{
	user();
}
