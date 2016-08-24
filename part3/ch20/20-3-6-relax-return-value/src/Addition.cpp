/*
 * Addition.cpp
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#include "Addition.h"
#include <iostream>
using namespace std;

Addition::Addition()
{
}

Addition::Addition(const Addition& a)
	: Expr(a)
{
}

void Addition::print() const
{
	cout << "instance of Addition class\n";
}
