/*
 * pointer_to_overloaded_function.cpp
 *
 *  Created on: 2016/05/11
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

void f(int);
int f(char);

void (*pf1)(int) = &f;
int (*pf2)(char) = &f;
//void (*pf3)(char) = &f;
	// no matches converting function 'f' to type 'void (*)(char)'

int main()
{
	pf1(12);
	pf2('x');
}

// undefs
void f(int i)
{
	cout << "f(int: " << i << ")\n";
}
int f(char c)
{
	cout << "f(char: " << c << ")\n";
}
