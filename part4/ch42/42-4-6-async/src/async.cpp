/*
 * async.cpp
 *
 *  Created on: 2017/01/28
 *      Author: sasaki
 */


#include <future>
#include <iostream>
using namespace std;

double square(int i) { return i*i; }

int main()
{
	future<double> fd = async(square,2);
	double d = fd.get();
	cout << "d: " << d << endl;

	auto fd2 = async(square,2);
	auto d2 = fd2.get();
	cout << "d2: " << d2 << endl;
}
