/*
 * shape.cpp
 *
 *  Created on: 2017/02/01
 *      Author: sasaki
 */

#include "shape.h"
using namespace std;

void draw_all(vector<unique_ptr<Shape>>& v)
{
	for (auto& p : v) p->draw();
}

void rotate_all(vector<unique_ptr<Shape>>& v, int angle)
{
	for (auto& p : v)
		p->rotate(angle);
}



