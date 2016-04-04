/*
 * future.cpp
 *
 *  Created on: 2016/04/04
 *      Author: sasaki
 */

#include <future>
using std::future;
using std::promise;

#include <exception>
using std::current_exception;

#include <thread>
using std::thread;

#include <utility>
using std::move;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

// 2016.04.04 change : why reference does not work ?
//void f(promise<int>& px)
void f(promise<int> px)
{
	try {
		int sum = 0;
		for (int i = 0; i < 10; ++i) {
			sum += i;
		}
		px.set_value(sum);
	}
	catch (...) {
		px.set_exception(current_exception());
	}
}

void g(future<int>& fx)
{
	try {
		int v = fx.get();
		cout << "g() gets " << v << endl;
	}
	catch (...) {
		cerr << "g() gets exception" << endl;
	}
}

int main()
{
	promise<int> px;
	future<int> fx = px.get_future();

	thread th {f, move(px)};	// why move(px) ?

	g(fx);

	th.join();
}

