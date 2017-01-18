/*
 * thread_id.cpp
 *
 *  Created on: 2017/01/18
 *      Author: sasaki
 */

#include <thread>
#include <iostream>
using namespace std;

void print_id(thread& t)
{
	if (t.get_id()==thread::id{})
		cout << "t not joinable\n";
	else
		cout << "t's id is " << t.get_id() << '\n';
}

void task()
{
	this_thread::sleep_for(chrono::seconds{3});
}

int main()
{
	thread th {task};
	print_id(th);
	th.join();
	print_id(th);
}
