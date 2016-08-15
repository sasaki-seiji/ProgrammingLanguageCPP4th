/*
 * Manager.h
 *
 *  Created on: 2016/08/15
 *      Author: sasaki
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Employee.h"

class Manager: public Employee {
	int rank;
public:
	Manager(int r, int id) : Employee{id}, rank{r} { }
	~Manager();
};

#endif /* MANAGER_H_ */
