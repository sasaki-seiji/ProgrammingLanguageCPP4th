/*
 * init.cpp
 *
 *  Created on: 2017/01/16
 *      Author: sasaki
 */

#include <thread>
#include <chrono>
#include <iostream>
using namespace std;

int x;
bool x_init;

int initialize()
{
	return 123;
}

void init()
{
	cout << "countdown:\n";
	for (int i=10; i>0; --i) {
		cout << i << std::endl;
		this_thread::sleep_for (chrono::seconds(1));
	}
	cout << "Lift off!\n";

	x = initialize();
	x_init = true;

	std::cout << "initialize done\n";
}

