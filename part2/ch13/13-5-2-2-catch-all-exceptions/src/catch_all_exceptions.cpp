/*
 * catch_all_exceptions.cpp
 *
 *  Created on: 2016/05/19
 *      Author: sasaki
 */

#include <stdexcept>
#include <iostream>
using namespace std;

void m()
{
	try {
		throw std::runtime_error("some error");
		//...
	}
	catch (std::exception& err) {
		cout << "rethrow in m()\n";
		throw;
	}
}

struct Error { };
void m2()
{
	try {
		throw Error{};
		//..
	}
	catch (...) {
		cout << "rethrow in m2()\n";
		throw;
	}
}

int main()
{
	try {
		m();
	}
	catch (std::exception& e) {
		cout << "caught in main(): " << e.what() << '\n';
	}

	try {
		m2();
	}
	catch (...) {
		cout << "caught in main(): m2() raise exception\n";
	}
}
