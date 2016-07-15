/*
 * user.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date1.h"
#include "Date2.h"
#include "Date3.h"
#include <iostream>
using namespace std;

void f()
{
	cout << "( ) form\n";

	Date1 today = Date1(23, 6, 1983);
	Date1 xmas(25, 12, 1990);
	//Date1 my_birthday;
		// no matching function for call to 'Date1::Date1()'
	//Date1 release1_0(10, 12);
		// no matching function for call to 'Date1::Date1(int, int)'
	today.print();
	xmas.print();
}

void g()
{
	cout << "{ } form\n";

	Date1 today = Date1 {23,6,1983};
	Date1 xmas {25,12,1990};
	//Date1 release1_0 {10,12};
		// no matching function for call to 'Date1::Date1(<brace-enclosed initializer list>)'
	today.print();
	xmas.print();
}

void h()
{
	cout << "constructor overload\n";

	Date2 today {4};
	Date2 july4 { "July 4, 1983" };
	Date2 guy {5,11};
	Date2 now;
	Date2 start { };

	today.print();
	july4.print();
	guy.print();
	now.print();
	start.print();
}

void i()
{
	cout << "constructor with default arguments\n";

	Date3 today {4};
	Date3 guy {5,11};
	Date3 now;
	Date3 start { };

	today.print();
	guy.print();
	now.print();
	start.print();
}

// add main
int main()
{
	f();
	g();
	h();
	i();
}
