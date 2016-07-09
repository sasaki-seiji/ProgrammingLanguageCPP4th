/*
 * file2.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */


extern int x;
int f();
void g() { x = f(); }

// add main
#include <iostream>
using namespace std;

int main()
{
	cout << "before g() call, x: " << x << '\n';
	g();
	cout << "after g() call, x: " << x << '\n';
}

