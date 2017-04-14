/*
 * user.cpp
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */


#include "diskptr.h"
#include "rec.h"

void update(const string& s)
{
	Disk_ptr<Rec> p {s};

	p->name = "Rescoe";
	++p->count;
}


// add main

int main()
{
	update("temp.dat");
}
