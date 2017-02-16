/*
 * struct_type_equality.cpp
 *
 *  Created on: 2016/04/21
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct S1 { int a; };
struct S2 { int a; };

S1 x;
//S2 y = x;
	// error: conversion from 'S1' to non-scalar type 'S2' requested

//int i = x;
	// error: cannot convert 'S1' to 'int' in initialization

int main()
{
	cout << "::x.a = " << ::x.a << endl;
}
