/*
 * user.cpp
 *
 *  Created on: 2016/10/06
 *      Author: sasaki
 */


#include "select.h"
using namespace Estd;

#include <typeinfo>
#include <iostream>
using namespace std;

Select<0,int,double,char> x0;
Select<1,int,double,char> x1;
Select<2,int,double,char> x2;
//Select<3,int,double,char> x3;
	// error: no type named ‘type’ in ‘struct Estd::select<3u, int, double, char>’

//Select<5,int,double,char> x5;
	// error: invalid use of incomplete type ‘struct Estd::select<2u>’

// add main

int main()
{
	cout << "typeid(x0).name(): " << typeid(x0).name() << '\n';
	cout << "typeid(x1).name(): " << typeid(x1).name() << '\n';
	cout << "typeid(x2).name(): " << typeid(x2).name() << '\n';
}

