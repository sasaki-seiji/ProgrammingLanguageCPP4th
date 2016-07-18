/*
 * user.cpp
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */

#include "Date.h"
#include <iostream>
using namespace std;

void f()
{
	Date::set_default(4,5,1945);
}

Date copy_of_default_date = Date{};
	// there is initializing order problem

void f(Date);

void g()
{
	f(Date{});
}

void f1(Date);
void f2(Date);
void f2(int);

void h()
{
	f1({});
	f2({});
	f2(Date{});
}

// define undef-func
void f(Date d)
{
	cout << "in f(Date d) - d: ";
	d.print();
}
void f1(Date d)
{
	cout << "in f1(Date d) - d: ";
	d.print();
}
void f2(Date d)
{
	cout << "in f2(Date d) - d: ";
	d.print();
}
void f2(int i)
{
	cout << "in f2(int i) - i: " << i << '\n';
}

// add main
int main()
{
	cout << "copy_of_default_date: ";
	copy_of_default_date.print();

	g();
	h();

	f();
	cout << "Date{} after f() call: ";
	Date{}.print();
}
