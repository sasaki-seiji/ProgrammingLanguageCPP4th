/*
 * user.cpp
 *
 *  Created on: 2016/08/15
 *      Author: sasaki
 */

#include "Employee.h"
#include "Manager.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "-- Employee* emp = new Employee{101};\n";
	Employee* emp = new Employee{101};

	cout << "-- delete emp;\n";
	delete emp;

	cout << "-- Employee* man = new Manager{\"software engineer dep.\", 1002};\n";
	Employee* man = new Manager{"software engineer dep.", 1002};

	cout << "-- delete man;\n";
	delete man;
}

