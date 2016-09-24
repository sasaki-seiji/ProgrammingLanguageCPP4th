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

// add main

int main()
{
	cout << "x: " << x << '\n';
	cout << "z: " << z << '\n';
}
