/*
 * user.cpp
 *
 *  Created on: 2016/08/29
 *      Author: sasaki
 */


#include "Commsat.h"
#include <iostream>
using namespace std;

void g(Comm_sat* p)
{
	highlight(p);
	Pos pos = center_of_gravity(p);
	cout << "pos: " << pos.x << ", " << pos.y << ", " << pos.z << '\n';
}

// add main

int main()
{
	Pos pos {10,0 ,-20};
	Comm_sat cs{pos};
	g(&cs);
}

