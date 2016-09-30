/*
 * user.cpp
 *
 *  Created on: 2016/09/30
 *      Author: sasaki
 */


#include "shape.h"
#include <cmath>
using namespace std;

void user()
{
	auto p = new Triangle<RGB,Bitmapped>{{0,0},{0,60},{30,sqrt(60*60-30*30)}};
	p->draw();

	auto q = new Circle<RGB,Bitmapped>{{50,50},10};
	q->draw();

	delete p;
	delete q;
}


// add main

int main()
{
	user();
}

