/*
 * file1.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */


//int g() { return f()+7; }
	// error: ‘f’ was not declared in this scope
//int f() { return x; }
	// error: 'x' was not declared in this scope
int x;

int f() { return x; }	// 'x' was not declared in this scope
int g() { return f()+7; } // undefined reference to `c'

// add main
#include <iostream>
using namespace std;
int main()
{
	cout << g() << '\n';
}
