/*
 * user.cpp
 *
 *  Created on: 2016/03/26
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

#include "shape.h"
#include "circle.h"
#include "smiley.h"

// 2016.03.26 dummy function
unique_ptr<Shape> read_shape(istream &is)
{
	string s;

	is >> s;

	if (s == "smiley"){
		Smiley *smiley = new Smiley(Point{5, 10}, 4);
		smiley->add_eye(new Circle(Point{4, 7}, 1));
		smiley->add_eye(new Circle(Point{6, 7}, 1));
		smiley->set_mouth(new Circle(Point{5, 3}, 2));
		return unique_ptr<Shape>{smiley};
	}
	else {
		return unique_ptr<Shape> {new Circle(Point{10, 5}, 3)} ;
	}
}

void user()
{
	std::vector<unique_ptr<Shape>> v;
	while(cin)
		v.push_back(read_shape(cin));
	draw_all(v);
	rotate_all(v, 45);
}

int main()
{
	user();
}
