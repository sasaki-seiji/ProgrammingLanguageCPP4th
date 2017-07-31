/*
 * assertion.cpp
 *
 *  Created on: 2017/07/31
 *      Author: sasaki
 */

#include "type_relation.h"
using namespace Estd;
#include "shape.h"
#include "circle.h"
#include "smiley.h"
#include <cassert>
#include <vector>
using namespace std;

template<typename T>
void draw_all(vector<T*>& v)
{
	static_assert(Is_base_of<Shape,T>(),"non-Shape type for draw_all()");

	for (auto p : v) {
		assert(p!=nullptr);
		p->draw();
	}
}

int main()
{
	Shape *circle = new Circle(Point{10,-10},3);
	Smiley* smiley = new Smiley(Point{0,0}, 10);
	smiley->set_mouth(new Circle(Point{0,-3}, 2));
	vector<Shape*> vs { circle, smiley, nullptr };
	draw_all(vs);

#if 0
	vector<int*> vi;
	draw_all(vi);
		// error: static assertion failed: non-Shape type for draw_all()
#endif
}
