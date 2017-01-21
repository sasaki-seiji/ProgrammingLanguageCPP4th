/*
 * mutex_error.cpp
 *
 *  Created on: 2017/01/21
 *      Author: sasaki
 */


#include <thread>
#include <mutex>
#include <iostream>
using namespace std;


void f()
{
	mutex mtx;
	try {
		cout << "locking mutex twice\n";
		mtx.lock();
		mtx.lock();
		cout << "locked mutex twice\n";
	}
	catch (system_error& e) {
		mtx.unlock();
		cout << e.what() << '\n';
		cout << e.code() << '\n';
	}
}

int main()
{
	thread t{f};
	t.join();
}
