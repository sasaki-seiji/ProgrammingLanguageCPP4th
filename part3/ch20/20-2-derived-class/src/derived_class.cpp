/*
 * derived_class.cpp
 *
 *  Created on: 2016/08/21
 *      Author: sasaki
 */

#include <string>
#include <list>
#include <iostream>
using namespace std;

struct Date {
	int y, m, d;
	Date(int yy=0, int mm=0, int dd=0) : y{yy}, m{mm}, d{dd} {}
};


struct Employee {
	string first_name, family_name;
	char middle_initial;
	Date hiring_date;
	short department;
};

struct Manager : public Employee {
	list<Employee*> group;
	short level;
};

void f(Manager m1, Employee e1)
{
	cout << "-- f(Manager,Employee) --\n";

	list<Employee*> elist {&m1, &e1};
	cout << "elist.size(): " << elist.size() << endl;
}

void g(Manager mm, Employee ee)
{
	cout << "-- g(Manager,Employee) --\n";

	Employee* pe = &mm;
	Manager* pm;

	//pm = &ee;
		// error: invalid conversion from 'Employee*' to 'Manager*' [-fpermissive]
	//pm->level = 2;

	pm = static_cast<Manager*>(pe);
	pm->level = 2;

	cout << "mm.level: " << mm.level << '\n';
}

// base class must be full defined

class Employee2;
//class Manger2 : public Employee2 { };
	// error: invalid use of incomplete type 'class Employee2'


// add main

int main()
{
	Employee e1 = { "seiji", "sasaki", '?', {1985, 4, 1}, 111 };
	Manager m1;

	f(m1, e1);
	g(m1, e1);
}
