/*
 * user.cpp
 *
 *  Created on: 2016/09/15
 *      Author: sasaki
 */


#include "Xref.h"
#include "forward.h"
#include <string>
#include <iostream>
using namespace std;

string x {"There and back again"};

Xref<string> r1 {7,"Here"};
Xref<string> r2 {9,x};
Xref<string> r3 {3,new string{"There"}};



// add main

int main()
{
	r1.print(cout);
	r2.print(cout);
	r3.print(cout);

	auto p1 = make_unique<Xref<string>>(17,"Here");
	p1.get()->print(cout);

	auto p2 = make_unique<Xref<string>>(19,x);
	p2.get()->print(cout);

	auto p3 = make_unique<Xref<string>,string>(27,"Here");
	p3.get()->print(cout);
}

