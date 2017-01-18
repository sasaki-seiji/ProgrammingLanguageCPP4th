/*
 * hardware_concurrency.cpp
 *
 *  Created on: 2017/01/18
 *      Author: sasaki
 */


#include <thread>
#include <iostream>
using namespace std;

int main()
{
	cout << "hardware_concurrency() returns " << thread::hardware_concurrency() << endl;
}
