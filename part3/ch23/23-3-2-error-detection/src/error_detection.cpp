/*
 * error_detection.cpp
 *
 *  Created on: 2016/09/10
 *      Author: sasaki
 */

#include "List.h"
#include <string>
using namespace std;

class Rec {
	string name;
	string address;
public:
	Rec(const char* n, const char* a) : name{n}, address{a} { }
	string get_name() const { return name; }
	string get_address() const { return address; }
};

ostream& operator<<(ostream& os, const Rec& r)
{
	os << "name: " << r.get_name() << '\n';
	os << "address: " << r.get_address() << '\n';
	return os;
}

void f(const List<int>&li, const List<Rec>& lr)
{
	li.print_all();
	lr.print_all();
}


// add main

int main()
{
	List<int> li0;
	List<int> li(10);
	li.add_head(20);
	li.add_head(-5);

	List<Rec> lr(Rec{"sasaki","kawasaki"});
	lr.add_head(Rec{"seiji", "hiroshima"});

	f(li, lr);
}

