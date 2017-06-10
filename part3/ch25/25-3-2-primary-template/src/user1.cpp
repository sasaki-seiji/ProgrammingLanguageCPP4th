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
	List1<int> list {10,20,30};
	int	v1,v2,v3;
	List1<int*> listp {&v1,&v2,&v3};

	cout << "list.size(): " << list.size() << '\n';
	cout << "listp.size(): " << listp.size() << '\n';
}
