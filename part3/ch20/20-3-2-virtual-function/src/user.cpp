/*
 * user.cpp
 *
 *  Created on: 2016/08/22
 *      Author: sasaki
 */



#include "Employee.h"
#include "Manager.h"

void print_list(const list<Employee*> s)
{
	for (auto x : s)
		x->print();
}

int main()
{
	Employee e {"Brown", 1234};
	Manager m {"Smith", 1234, 2};

	print_list({&m, &e});
}
