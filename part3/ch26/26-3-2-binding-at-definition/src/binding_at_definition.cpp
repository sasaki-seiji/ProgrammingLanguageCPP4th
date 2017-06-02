/*
 * binding_at_definition.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

int x;

template<typename T>
T f(T a)
{
	++x;
	//++y;
		// error: 'y' was not declared in this scope
	return a;
}

int y;

int z = f(2);

void g(double);
void g2(double);

template<typename T>
int ff(T a)
{
	g2(2);
	//g3(2);
		// error: there are no arguments to ‘g3’ that depend on a template parameter, so a declaration of ‘g3’ must be available [-fpermissive]
	g(a);

	return 123;
}

void g(int);
void g3(int);

int xx = ff(5);


// undefs

void g(double d) { cout << "g(double: " << d << ")\n"; }
void g2(double d) { cout << "g2(double: " << d << ")\n"; }
void g(int i) { cout << "g(int: " << i << ")\n"; }
void g3(int i) { cout << "g3(int: " << i << ")\n"; }


// add main

int main()
{
	cout << "x: " << x << endl;
	cout << "z: " << z << endl;
	cout << "xx: " << xx << endl;
}
