/*
 * Manager.cpp
 *
 *  Created on: 2016/08/15
 *      Author: sasaki
 */

#include "Manager.h"
#include <iostream>
using namespace std;

Manager::Manager(const string& d, int id) : Employee{id}, dep{d}
{
	cout << "Manager::Manager(" << d << "," << id << ")\n";
}

Manager::~Manager()
{
	cout << "Manager::~Manager()\n";
}
