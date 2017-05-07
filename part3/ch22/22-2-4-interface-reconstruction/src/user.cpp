/*
 * user.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#include "Ioobj.h"
#include "Shape.h"
#include "Ioshape.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <exception>
using namespace std;

void user(const char* name)
{
	cout << "-- user(\"" << name << "\") --\n";

	ifstream ss;
	ss.open(name);

	unique_ptr<Io_obj> p {get_obj(ss)};

	if (auto sp = dynamic_cast<Shape*>(p.get())) {
		sp->draw();
	}
	else {
		cout << "not shape!\n";
	}
}


// add main

int main()
{
	io_map["Io_circle"] = &Io_circle::new_circle;
	io_map["Io_triangle"] = &Io_triangle::new_triangle;

	try {
		user("circle.txt");
		user("triangle.txt");
	}
	catch (const exception& e) {
		cout << e.what() << '\n';
	}
	catch (...) {
		cout << "unknown error occurred!\n";
	}
}
