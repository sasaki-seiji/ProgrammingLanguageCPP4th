/*
 * union.cpp
 *
 *  Created on: 2016/04/21
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

enum Type { str, num };

struct Entry {
	char* name;
	Type t;
	char* s;
	int i;
};

void f(Entry* p)
{
	cout << "-- f(Entry*) --\n";

	if (p->t == str)
		cout << p->s << '\n';
	else
		cout << p->i << '\n';
}

union Value {
	char* s;
	int i;
};

struct Entry2 {
	char* name;
	Type t;
	Value v;
};

void f(Entry2 *p)
{
	cout << "-- f(Entry2*) --\n";

	if (p->t == str)
		cout << p->v.s << '\n';
	else
		cout << p->v.i << '\n';
}

union Fudge {
	int i;
	int* p;
};

int* cheat(int i)
{
	Fudge a;
	a.i = i;
	return a.p;
}

int* cheat2(int i)
{
	return reinterpret_cast<int*>(i);
}

int main()
{
	char name[] = "name";
	char value[] = "something";

	Entry e;
	e.name = name;
	e.t = str;
	e.s = value;
	f(&e);
	e.t = num;
	e.i = 1234;
	f(&e);

	Entry2 e2;
	e2.name = name;
	e2.t = str;
	e2.v.s = value;
	f(&e2);
	e2.t = num;
	e2.v.i = 5678;
	f(&e2);


	cout << "cheat(10) returns " << cheat(10) << '\n';
	cout << "cheat2(10) returns " << cheat2(10) << '\n';
}

