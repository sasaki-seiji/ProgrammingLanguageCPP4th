/*
 * type_field.cpp
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
	enum Empl_type { man, empl };
	Empl_type type;

	Employee() : type{empl} { }

	string first_name, family_name;
	char middle_initial;

	Date hiring_date;
	short department;
};

struct Manager : public Employee {
	Manager() { type = man; }

	list<Employee*> group;
	short level;
};


void print_employee(const Employee* e)
{
	switch (e->type) {
	case Employee::empl:
		cout << e->family_name << '\t' << e->department << '\n';
		break;
	case Employee::man:
	{
		cout << e->family_name << '\t' << e->department << '\n';
		const Manager* p = static_cast<const Manager*>(e);
		cout << " level " << p->level << '\n';
		break;
	}
	}
}

void print_list(const list<Employee*>& elist)
{
	cout << "-- print_list(const list<Employee*>&) --\n";

	for (auto x : elist)
		print_employee(x);
}

void print_employee2(const Employee* e)
{
	cout << e->family_name << '\t' << e->department << '\n';

	if (e->type == Employee::man) {
		const Manager* p = static_cast<const Manager*>(e);
		cout << " level " << p->level << '\n';
	}
}

void print_list2(const list<Employee*>& elist)
{
	cout << "-- print_list2(const list<Employee*>&) --\n";

	for (auto x : elist)
		print_employee2(x);
}


// add main

int main()
{
	Employee e1, e2;
	e1.family_name = "emp1";
	e1.department = 123;
	e2.family_name = "emp2";
	e2.department = 123;

	Manager m1;
	m1.family_name = "man1";
	m1.department = 123;
	m1.group.push_back(&e1);
	m1.group.push_back(&e2);
	m1.level = 3;

	list<Employee*> elist {&e1, &m1, &e2};
	print_list(elist);

	print_list2(elist);
}
