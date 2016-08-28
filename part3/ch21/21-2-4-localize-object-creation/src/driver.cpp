/*
 * driver.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "Ivalmaker.h"
#include "BBmaker.h"
#include "LSmaker.h"

void user(Ival_maker&);

BB_maker BB_impl;
LS_maker LS_impl;

void driver()
{
	user(BB_impl);
	user(LS_impl);
}

int main()
{
	driver();
}
