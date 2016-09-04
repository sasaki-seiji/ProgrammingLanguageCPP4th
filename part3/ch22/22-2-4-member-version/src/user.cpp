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
	ifstream ss;
	ss.open(name);

	unique_ptr<Io_obj> p {get_obj(ss)};

	if (auto sp = get_val<Circle>(p.get())) {
		sp->draw();
	}
	else if(auto sp = get_val<Triangle>(p.get())) {
		sp->draw();
	}
	else if(auto sp = get_val<int>(p.get())) {
		cout << "int: " << *sp << '\n';
	}
	else {
		cout << "not shape!\n";
	}
}


// add main

int main()
{
	io_map["Io_circle"] = &Io_circle::new_io;
	io_map["Io_triangle"] = &Io_triangle::new_io;
	io_map["Io_int"] = &Io_int::new_io;

	try {
		user("circle.txt");
		user("triangle.txt");
		user("int.txt");
	}
	catch (const exception& e) {
		cout << e.what() << '\n';
	}
	catch (...) {
		cout << "unknown error occurred!\n";
	}
}
