/*
 * user.cpp
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */


#include "common.h"
using namespace Estd;

#include <typeinfo>
#include <complex>
#include <string>
#include <iostream>
using namespace std;

struct Base { };
struct Derived : Base { };

int main()
{
	bool b1 = Common<int,long>();
	bool b2 = Common<int,complex<double>>();
	bool b3 = Common<Base*,Derived*>();
	bool b4 = Common<int,string>();

	cout << boolalpha;
	cout << "Common<int,long>(): " << b1
			<< ", Common_type: " <<  typeid(Common_type<int,long>).name() << endl;
	cout << "Common<int,complex<double>>(): " << b2
			<< ", Common_type: " <<  typeid(Common_type<int,complex<double>>).name() << endl;
	cout << "Common<Base*,Derived*>>(): " << b3
			<< ", Common_type: " <<  typeid(Common_type<Base*,Derived*>).name() << endl;
	cout << "Common<int,string>(): " << b4
			<< ", Common_type: " <<  typeid(Common_type<int,string>).name() << endl;
}

