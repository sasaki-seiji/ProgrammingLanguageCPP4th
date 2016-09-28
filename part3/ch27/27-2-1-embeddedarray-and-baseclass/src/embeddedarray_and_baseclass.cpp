/*
 * embeddedarray_and_baseclass.cpp
 *
 *  Created on: 2016/09/28
 *      Author: sasaki
 */

#include "shape.h"
#include <iostream>
using namespace std;

void maul(Shape* p, int n)
{
	for (int i=0; i!=n; ++i)
		p[i].draw();
}

void user()
{
	Circle image[10];
	//maul(image,10);
	maul(image,1);
}


// add main

int main()
{
	try {
		user();
	}
	catch(...)
	{
		cerr << "error!\n";
	}
}
