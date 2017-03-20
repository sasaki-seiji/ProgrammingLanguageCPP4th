/*
 * user.cpp
 *
 *  Created on: 2016/05/27
 *      Author: sasaki
 */


#include "A.h"
#include "B.h"

#include <iostream>
using namespace std;

void g()
{
	cout << "-- old g() --\n";
	f('a');
}
