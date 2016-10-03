/*
 * user.cpp
 *
 *  Created on: 2016/10/03
 *      Author: sasaki
 */


#include "objholder.h"
#include <array>
#include <iostream>
using namespace std;

void f()
{
	typename Obj_holder<double>::type v1;
	typename Obj_holder<array<double,200>>::type v2;

	*v1 = 7.7;
	(*v2)[77] = 9.9;

	cout << "*v1: " << *v1 << '\n';
	cout << "(*v2)[77]: " << (*v2)[77] << '\n';
}

// add main

int main()
{
	f();
}
