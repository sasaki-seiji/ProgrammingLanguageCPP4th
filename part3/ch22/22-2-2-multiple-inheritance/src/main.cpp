/*
 * main.cpp
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#include "Radio.h"

void h1(Radio&);
void h2(Storable*);

int main()
{
	Radio r;
	h1(r);

	Transmitter tr;
	h2(&tr);

	h2(&r);
}
