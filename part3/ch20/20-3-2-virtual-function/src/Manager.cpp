/*
 * Manager.cpp
 *
 *  Created on: 2016/08/22
 *      Author: sasaki
 */

#include "Manager.h"
#include <iostream>
using namespace std;

Manager::Manager(const string& name, int dept, int lvl)
	: Employee{name, dept}, level{lvl}
{
}

void Manager::print() const
{
	Employee::print();
	cout << "\tlevel " << level << '\n';
}

