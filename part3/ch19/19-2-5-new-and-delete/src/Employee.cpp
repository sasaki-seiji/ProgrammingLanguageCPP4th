/*
 * Employee.cpp
 *
 *  Created on: 2016/08/15
 *      Author: sasaki
 */

#include "Employee.h"
#include <iostream>
using namespace std;

void* Employee::operator new(size_t s)
{
	cout << "Employee::operator new(" << s << ")\n";
	return ::operator new(s);
}

void Employee::operator delete(void* p, size_t s)
{
	cout << "Employee::operator delete(" << p << ", " << s << ")\n";
	//::operator delete(p, s);
		// error: invalid conversion from 'std::size_t {aka long long unsigned int}' to 'void*' [-fpermissive]
	::operator delete(p);
}

Employee::~Employee()
{
	cout << "Employee::~Employee()\n";
}
