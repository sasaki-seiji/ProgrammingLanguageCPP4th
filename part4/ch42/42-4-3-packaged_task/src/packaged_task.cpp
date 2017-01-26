/*
 * packaged_task.cpp
 *
 *  Created on: 2017/01/26
 *      Author: sasaki
 */


#include <future>
#include <iostream>
using namespace std;

int ff(int i)
{
	if (i) return i;
	throw runtime_error("ff(0)");
}

void test_packaged_task()
{
	packaged_task<int(int)> pt1 {ff};
	packaged_task<int(int)> pt2 {ff};

	pt1(1);
	pt2(0);

	auto v1 = pt1.get_future();
	auto v2 = pt2.get_future();

	try {
		cout << v1.get() << '\n';
		cout << v2.get() << '\n';
	}
	catch (exception& e) {
		cout << "exception: " << e.what() << '\n';
	}
}

void direct_task_call()
{
	try {
		cout << ff(1) << '\n';
		cout << ff(0) << '\n';
	}
	catch (exception& e) {
		cout << "exception: " << e.what() << '\n';
	}
}

int main()
{
#if 0
	test_packaged_task();
#else
	thread th {test_packaged_task};
	th.join();
#endif

	direct_task_call();
	return 0;
}
