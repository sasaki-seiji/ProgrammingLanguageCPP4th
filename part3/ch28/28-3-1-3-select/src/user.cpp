/*
 * user.cpp
 *
 *  Created on: 2016/10/06
 *      Author: sasaki
 */


#include "select.h"
#include <typeinfo>
#include <iostream>
using namespace std;

Select<0,int,double,char> x0;
Select<1,int,double,char> x1;
Select<2,int,double,char> x2;
Select<3,int,double,char> x3;

//Select<5,int,double,char> x5;
	// error: invalid use of incomplete type ‘struct myselect<5, int, double, char, Nil>’

// add main

int main()
{
	cout << "typeid(x0).name(): " << typeid(x0).name() << '\n';
	cout << "typeid(x1).name(): " << typeid(x1).name() << '\n';
	cout << "typeid(x2).name(): " << typeid(x2).name() << '\n';
	cout << "typeid(x3).name(): " << typeid(x3).name() << '\n';
}

