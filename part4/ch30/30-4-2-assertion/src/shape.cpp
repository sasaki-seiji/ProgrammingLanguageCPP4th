/*
 * shape.cpp
 *
 *  Created on: 2017/02/01
 *      Author: sasaki
 */


#include "shape.h"
using namespace std;

#if 0
void draw_all(vector<Shape*>& v)
{
	for (auto p : v) p->draw();
}
#endif

void rotate_all(vector<Shape*>& v, int angle)
{
	for (auto p : v)
		p->rotate(angle);
}



