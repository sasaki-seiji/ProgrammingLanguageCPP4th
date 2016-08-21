/*
 * Manager.cpp
 *
 *  Created on: 2016/08/21
 *      Author: sasaki
 */

#include "Manager.h"
#include <iostream>
using namespace std;

Manager::Manager(const string& first, const string& family, char middle, short l)
	: Employee{first, family, middle}, level{l}
{ }


void Manager::print() const
{
	//cout << "name is " << full_name() << '\n';
	Employee::print();
	//print();
	cout << level;
}
