/*
 * overload_manual_resolve.cpp
 *
 *  Created on: 2016/05/08
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void f1(char);
void f1(long);

inline void f1(int n) { f1(long(n)); }

void f2(char*);
void f2(int*);

void k(int i)
{
	f1(i);
	//f2(0);
	f2(static_cast<int*>(0));
}

int main()
{
	k(123);
}

// undefs
void f1(long l)
{
	cout << "f1(long: " << l << ")\n";
}
void f2(int* p)
{
	cout << "f2(int*: " << p << ")\n";
}
