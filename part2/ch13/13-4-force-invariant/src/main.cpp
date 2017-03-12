/*
 * main.cpp
 *
 *  Created on: 2016/05/16
 *      Author: sasaki
 */

#include <iostream>
using std::cout;
using std::cerr;

#include "Assert.h"

constexpr int max = 10;

void f(int n)
{
	cout << "-- f(" << n << ") --\n";
	Assert::dynamic<Assert::level(2), Assert::Error>(
			(1<=n && n<max), Assert::compose(__FILE__, __LINE__, "range problem"));
}

void f2(int n)
{
	cout << "-- f2(" << n << ") --\n";
	Assert::dynamic((1<=n && n<max), Assert::compose(__FILE__, __LINE__, "range problem"));
}

void f3(int n)
{
	cout << "-- f3(" << n << ") --\n";
	Assert::dynamic(1<=n && n<max);
}

int main()
{
	try {
		f(5);
		f(10);
	}
	catch (Assert::Error& e) {
		cout << e.what() << '\n';
	}

	try {
		f2(5);
		f2(10);
	}
	catch (Assert::Error& e) {
		cout << e.what() << '\n';
	}

	try {
		f3(5);
		f3(10);
	}
	catch (Assert::Error& e) {
		cout << e.what() << '\n';
	}

}
