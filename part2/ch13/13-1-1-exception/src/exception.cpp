/*
 * exception.cpp
 *
 *  Created on: 2016/05/13
 *      Author: sasaki
 */

#include <iostream>
using std::cout;

struct Some_error { };

int do_task();

bool succeeded = true;

void taskmaster()
{
	try {
		auto result = do_task();
		cout << "result: " << result << '\n';
	}
	catch (Some_error) {
		// 	Catching by reference is recommended 'Some_error'

		cout << "do_task() throws Some_error\n";
	}
}

int do_task()
{
	int result = 12;
	if (succeeded)
		return result;
	else
		throw Some_error{};
}

struct Range_error { };
const int max = 10;

void f(int n)
{
	cout << "f(" << n << ")\n";

	if (n < 0 || max < n) throw Range_error{ };
}

int main()
{
	taskmaster();
	succeeded = false;
	taskmaster();

	try {
		f(5);
		f(11);
	}
	catch (Range_error& e) {
		cout << "catched Range_error\n";
	}
}
