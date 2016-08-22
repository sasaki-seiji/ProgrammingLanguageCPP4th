/*
 * Employee.h
 *
 *  Created on: 2016/08/22
 *      Author: sasaki
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
using std::string;

class Employee {
public:
	Employee(const string& name, int dept);
	virtual void print() const;
private:
	string first_name, family_name;
	short department;

};

#endif /* EMPLOYEE_H_ */
