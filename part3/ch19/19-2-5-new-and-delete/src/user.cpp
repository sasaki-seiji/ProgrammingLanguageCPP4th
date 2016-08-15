/*
 * user.cpp
 *
 *  Created on: 2016/08/15
 *      Author: sasaki
 */

#include "Employee.h"
#include "Manager.h"

int main()
{
	Employee* emp = new Employee{101};
	delete emp;

	Employee* man = new Manager{"software engineer dep.", 1002};
	delete man;
}

