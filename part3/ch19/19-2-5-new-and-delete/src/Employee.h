/*
 * Employee.h
 *
 *  Created on: 2016/08/15
 *      Author: sasaki
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <cstddef>
using std::size_t;

class Employee {
	int id;
public:
	Employee(int i);
	virtual ~Employee();

	void* operator new(size_t);
	void operator delete(void*, size_t);

	void* operator new[](size_t);
	void operator delete[](void*, size_t);
};

#endif /* EMPLOYEE_H_ */
