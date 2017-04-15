/*
 * Manager.h
 *
 *  Created on: 2016/08/15
 *      Author: sasaki
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Employee.h"
#include <string>
using std::string;

class Manager: public Employee {
	string dep;
public:
	Manager(const string& d, int id);
	~Manager();
};

#endif /* MANAGER_H_ */
