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
		throw;
	}
}

int main()
{
	try {
		m();
	}
	catch (std::exception& e) {
		cerr << e.what() << '\n';
	}

	try {
		m2();
	}
	catch (...) {
		cerr << "m2() raise exception\n";
	}
}
