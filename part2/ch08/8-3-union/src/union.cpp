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
	if (p->t == str)
		cout << p->s;
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
	if (p->t == str)
		cout << p->v.s;
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
	Entry e;
	e.name = "Entry";
	e.t = str;
	e.s = "some string\n";
	f(&e);

	Entry2 e2;
	e2.name = "Entry2";
	e2.t = str;
	e2.v.s = "other string\n";
	f(&e2);

	cout << "cheat(10) returns " << cheat(10) << '\n';
	cout << "cheat2(10) returns " << cheat2(10) << '\n';
}

