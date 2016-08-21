/*
 * Manager.h
 *
 *  Created on: 2016/08/21
 *      Author: sasaki
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Employee.h"

class Manager : public Employee{
public:
	void print() const;

	Manager(const string& first, const string& family, char middle, short l);
private:
	short level;
};

#endif /* MANAGER_H_ */
