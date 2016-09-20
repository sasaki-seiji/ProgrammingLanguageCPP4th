/*
 * user2.cpp
 *
 *  Created on: 2016/09/20
 *      Author: sasaki
 */


#include "List2.h"
#include <iostream>
using namespace std;

void user2()
{
	int v = 100;
	List2<int*> lp{&v};
	cout << "lp.get(): " << lp.get() << '\n';
}
