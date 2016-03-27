/*
 * manage_resource.cpp
 *
 *  Created on: 2016/03/27
 *      Author: sasaki
 */

#include <vector>
#include <thread>
#include <iostream>
#include "Vector.h"

std::vector<std::thread> my_threads;

// 2016.03.27 add
void heartbeat()
{
	std::cout << "heartbeat() called\n";
}

Vector init(int n)
{
	std::thread t {heartbeat};
	my_threads.push_back(std::move(t));

	Vector vec(n);
	for (int i = 0 ; i != vec.size(); ++i) vec[i] = 777;
	return vec;
}

int main()
{
	auto v = init(10000);

	// 2016.03.27 add
	for (auto& th : my_threads) th.join();
}


