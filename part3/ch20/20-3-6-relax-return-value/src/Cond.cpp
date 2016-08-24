/*
 * Cond.cpp
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#include "Cond.h"
#include <iostream>
using namespace std;

Cond::Cond()
{
}

Cond::Cond(const Cond& c)
	: Expr(c)
{
}

void Cond::print() const
{
	cout << "instance of Cond class\n";
}
