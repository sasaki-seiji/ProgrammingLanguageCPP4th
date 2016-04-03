/*
 * resource_management.cpp
 *
 *  Created on: 2016/04/03
 *      Author: sasaki
 */

#include <mutex>
#include <iostream>
using namespace std;

mutex m;

void f()
{
	unique_lock<mutex> lck {m};

	cout << "now locked mutex\n";
}

int main()
{
	f();
}
