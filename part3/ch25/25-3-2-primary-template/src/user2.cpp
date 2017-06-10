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
	int v1, v2, v3;
	List2<int*> lp{&v1, &v2, &v3};
	cout << "lp.size(): " << lp.size() << '\n';
}
