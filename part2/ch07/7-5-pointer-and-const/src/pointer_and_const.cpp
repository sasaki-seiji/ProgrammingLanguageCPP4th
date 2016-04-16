/*
 * pointer_and_const.cpp
 *
 *  Created on: 2016/04/16
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

#include <string.h>

const int model = 90;
const int v[] = { 1, 2, 3, 4 };
//const int x;
	// uninitialized const 'x' [-fpermissive]

void f()
{
	//model = 200;
		// assignment of read-only variable 'model'
	//v[2] = 3;
		// assignment of read-only location 'v[2]'
}

struct X { int x; };

void g(const X* p)
{
	cout << p->x << '\n';
}

void g()
{
	X val;
	val.x = 10;
	g(&val);
	val.x = 20;
}

void f1(char* p)
{
	char s[] = "Gorm";

	const char* pc = s;
	//pc[3] = 'g';
		// assignment of read-only location '*(pc + 3u)'

	pc = p;

	char *const cp = s;
	cp[3] = 'a';
	//cp = p;
		// assignment of read-only variable 'cp'

	const char *const cpc = s;
	//cpc[3] = 'a';
		// assignment of read-only location '*(((const char*)cpc) + 3u)'

	//cpc = p;
		// assignment of read-only variable 'cpc'

	cout << "pc = " << pc << '\n';
	cout << "cp = " << cp << '\n';
	cout << "cpc = " << cpc << '\n';
}

void f4()
{
	int a = 1;
	const int c = 2;

	const int* p1 = &c;
	const int* p2 = &a;
	//int* p3 = &c;
		// invalid conversion from 'const int*' to 'int*' [-fpermissive]
	//*p3 = 7;

	cout << "*p1 = " << *p1 << '\n';
	cout << "*p2 = " << *p2 << '\n';
}

int main()
{
	g();
	char v[] = "string";
	f1(v);

	const char *pc = strchr("string", 'g');
	char *p = strchr(v, 'r');
	cout << "*pc = " << *pc << '\n';
	cout << "*p = " << *p << '\n';

	f4();
}

