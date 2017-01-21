/*
 * cout_mutex.cpp
 *
 *  Created on: 2017/01/21
 *      Author: sasaki
 */


#include <thread>
#include <mutex>
#include <iostream>
using namespace std;

mutex cout_mutex;

void hello()
{
	cout_mutex.lock();
	cout << "Hello, ";
	cout_mutex.unlock();
}

void world()
{
	cout_mutex.lock();
	cout << "World!";
	cout_mutex.unlock();
}

int main()
{
	thread t1 {hello};
	thread t2 {world};

	t1.join();
	t2.join();
}
