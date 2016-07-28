/*
 * user.cpp
 *
 *  Created on: 2016/07/28
 *      Author: sasaki
 */

#include "Club.h"
#include <iostream>
using namespace std;

class X {
	const int i;
	Club cl;
	Club& rc;

public:
	X(int ii, const string& n, Date d, Club& c) : i{ii}, cl{n,d}, rc{c} {}
};

class Person {
	string name;
	string address;

public:
	Person(const Person&);
	Person(const string& n, const string&a);
	void print(ostream& os);
};

Person::Person(const string& n, const string& a)
	: name{n}
{
	address = a;
}

void Person::print(ostream& os)
{
	os << "Person(" << name << ", " << address << ")\n";
}

int main()
{
	Club club { "club-name-A", Date{1,1,1970}};
	X x {10, "club-name-B", Date{25,12,1959}, club};

	Person p {"sasaki", "kawasaki" };
	p.print(cout);
}
