/*
 * Employee.cpp
 *
 *  Created on: 2016/08/21
 *      Author: sasaki
 */

#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(const string& first, const string& family, char middle)
	: first_name{first}, family_name{family}, middle_initial{middle}
{ }

void Employee::print() const
{
	cout << "name is " << full_name() << '\n';
}
