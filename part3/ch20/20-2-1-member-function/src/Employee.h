/*
 * Employee.h
 *
 *  Created on: 2016/08/21
 *      Author: sasaki
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
using std::string;

class Employee {
public:
	void print() const;
	string full_name() const
		{ return first_name + ' ' + middle_initial + ' ' + family_name; }

	Employee(const string& first, const string& family, char middle);
private:
	string first_name, family_name;
	char middle_initial {'?'};
};

#endif /* EMPLOYEE_H_ */
