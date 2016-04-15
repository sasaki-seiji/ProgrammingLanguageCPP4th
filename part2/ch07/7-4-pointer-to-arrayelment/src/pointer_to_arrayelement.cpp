/*
 * pointer_to_arrayelement.cpp
 *
 *  Created on: 2016/04/15
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

#include <string.h>

int v[] = { 1, 2, 3, 4 };
int* p1 = v;
int* p2 = &v[0];
int* p3 = v+4;

int* p4 = v-1;
int* p5 = v+7;

void f()
{
	char v[] = "Annemarie";
	char* p = v;
	cout << "strlen(p) = " << strlen(p) << '\n';
	cout << "strlen(v) = " << strlen(v) << '\n';
	//v = p;
		// incompatible types in assignment of 'char*' to 'char [10]'
}

int main()
{
	cout << "v = " << v << '\n';
	cout << "p1 = " << p1 << '\n';
	cout << "p2 = " << p2 << '\n';
	cout << "p3 = " << p3 << '\n';
	cout << "p4 = " << p4 << '\n';
	cout << "p5 = " << p5 << '\n';

	f();
}


