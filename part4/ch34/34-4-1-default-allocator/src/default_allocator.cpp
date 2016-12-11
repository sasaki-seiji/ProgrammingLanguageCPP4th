/*
 * default_allocator.cpp
 *
 *  Created on: 2016/12/10
 *      Author: sasaki
 */

#include "allocator.h"
#include "list.h"
#include <string>
#include <iostream>
using namespace std;

constexpr int sz {100000};
Arena my_arena1{new char[sz], sz};

int main()
{
	cout << "-- use default allocator --\n";
	List<string> ls1;
	ls1.push_front("string#1");
	ls1.push_front("string#2");
	ls1.push_front("string#3");
	ls1.print(cout);
	cout << "ls1.front(): " << ls1.front() << endl;
	ls1.pop_front();
	ls1.print(cout);


	cout << "-- use Simple_alloc --\n";
	List<string, Simple_alloc<string>> ls2;
	ls2.push_front("ls2#1");
	ls2.push_front("ls2#2");
	ls2.push_front("ls2#3");
	ls2.print(cout);
	cout << "ls2.front(): " << ls2.front() << endl;
	ls2.pop_front();
	ls2.print(cout);

	cout << "-- use My_alloc --\n";
	//My_alloc<string> alloc{my_arena1};
	List<string, My_alloc<string>> ls3{My_alloc<string>{my_arena1}};
	ls3.push_front("ls3#1");
	ls3.push_front("ls3#2");
	ls3.push_front("ls3#3");
	ls3.print(cout);
	cout << "ls3.front(): " << ls3.front() << endl;
	ls3.pop_front();
	ls3.print(cout);

}
