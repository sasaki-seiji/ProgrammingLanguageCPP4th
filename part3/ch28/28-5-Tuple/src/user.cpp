/*
 * user.cpp
 *
 *  Created on: 2016/10/13
 *      Author: sasaki
 */


#include "Tuple.h"
#include <string>
#include <iostream>
using namespace std;

Tuple<double,string,int,char> t{3.14,"Bob",127,'c'};

class F0 { };

typedef Tuple<int*,int*> T0;
typedef Tuple<int*,F0> T1;
typedef Tuple<int*,F0,F0> T2;
typedef Tuple<int*,F0,F0,F0> T3;

// add main

int main()
{
	cout << "sizeof(T0): " << sizeof(T0) << '\n';
	cout << "sizeof(T1): " << sizeof(T1) << '\n';
	cout << "sizeof(T2): " << sizeof(T2) << '\n';
	cout << "sizeof(T3): " << sizeof(T3) << '\n';

	cout << "sizeof(t): " << sizeof(t) << '\n';
}
