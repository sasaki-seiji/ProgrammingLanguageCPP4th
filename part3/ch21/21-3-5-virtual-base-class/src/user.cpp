/*
 * user.cpp
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */


#include "Radio.h"

void f(Storable* sp)
{
	sp->write();
}

// add main

int main()
{
	Radio r("temp.txt");
	f(&r);
}
