/*
 * Manager.h
 *
 *  Created on: 2016/08/22
 *      Author: sasaki
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Employee.h"
#include <list>
using std::list;

class Manager : public Employee {
public:
	Manager(const string& name, int dept, int lvl);
	void print() const;
private:
	list<Employee*> group;
	short level;
};

#endif /* MANAGER_H_ */
