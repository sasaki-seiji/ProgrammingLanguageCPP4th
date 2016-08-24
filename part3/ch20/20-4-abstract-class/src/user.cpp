/*
 * user.cpp
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */


#include "Shape.h"
#include "Circle.h"
#include "Polygon.h"
#include "Irregularpolygon.h"

#include "Serialdevice.h"

#include <iostream>
using namespace std;

//Shape s;
	// error: cannot declare variable 's' to be of abstract type 'Shape'

Point p1{1,2}, p2{2,3}, p3{3,4}, p4{4,5};
//Polygon b { p1, p2, p3, p4 };
	// error: cannot declare variable 'b' to be of abstract type 'Polygon'

void use(Shape* s)
{
	s->rotate(100);
	s->draw();
	cout << "s->is_closed() ? " << s->is_closed() << '\n';
}


const int opt = 10;
const int size = 100;

void operate_device(Character_device* dev)
{
	char	buf[size];

	dev->open(opt);
	dev->close(opt);
	dev->read(buf, size);
	dev->write(buf, size);
	dev->ioctl(opt);
}

// add main

int main()
{
	Point pt {2, 5};
	Circle c{pt, 3};

	use(&c);

	Irregular_polygon ip{p1,p2,p3,p4};
	use(&ip);

	Serial_device sd{2};
	operate_device(&sd);
}
