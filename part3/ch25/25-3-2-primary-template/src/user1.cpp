/*
 * user1.cpp
 *
 *  Created on: 2016/09/20
 *      Author: sasaki
 */


#include "List1.h"
#include <iostream>
using namespace std;

void user1()
{
	List1<int> list{10};
	int	v = 100;
	List1<int*> listp{&v};

	cout << "list.get(): " << list.get() << '\n';
	cout << "listp.get(): " << listp.get() << '\n';
}
