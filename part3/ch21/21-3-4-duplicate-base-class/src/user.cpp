/*
 * user.cpp
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */


#include "Radio.h"
#include <iostream>
using namespace std;

void f(Radio* p)
{
	string name = p->get_file();
	cout << "p->get_file() returns: " << name << '\n';
	p->read();
	p->write();
}

// add main

int main()
{
	Radio r;
	f(&r);
}
