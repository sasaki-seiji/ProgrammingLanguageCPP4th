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
	RGB	rgb;
	Bitmapped bitmapped;

	auto p = new Triangle{{0,0},{0,60},{30,sqrt(60*60-30*30)}};
	p->configure(rgb,bitmapped);
	p->draw();

	auto q = new Circle{{50,50},10};
	q->configure(rgb,bitmapped);
	q->draw();

	delete p;
	delete q;
}


// add main

int main()
{
	user();
}

