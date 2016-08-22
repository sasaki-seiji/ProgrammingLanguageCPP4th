/*
 * Employee.cpp
 *
 *  Created on: 2016/08/22
 *      Author: sasaki
 */

#include "Employee.h"
#include <iostream>
using namespace std;


Employee::Employee(const string& name, int dept)
	: family_name{name}, department{dept}
{
}

void Employee::print() const
{
	cout << family_name << '\t' << department << '\n';
}
