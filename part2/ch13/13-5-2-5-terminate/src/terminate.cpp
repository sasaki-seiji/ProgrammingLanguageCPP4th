/*
 * terminate.cpp
 *
 *  Created on: 2016/05/21
 *      Author: sasaki
 */

#include <exception>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
using namespace std;

[[noreturn]] void my_handler()
{
	cerr << "exiting program\n";
	exit(1);
}

void some_func()
{
	throw runtime_error("error");
}

void dangerous()
{
	terminate_handler old = set_terminate(my_handler);
	some_func();
	set_terminate(old);
}

int main()
{
	dangerous();
}
