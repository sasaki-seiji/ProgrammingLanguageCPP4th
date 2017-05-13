/*
 * user.cpp
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */


#include "List.h"
#include "Allocator.h"
#include <iostream>
using namespace std;

int main()
{
	List<int, My_allocator> lim;
	lim.push_front(10);
	lim.push_front(20);
	lim.print_all(cout);

	List<string, My_allocator> lsm;
	lsm.push_front("string");
	lsm.push_front("test");
	lsm.print_all(cout);

	List<int, Your_allocator> liy;
	liy.push_front(10);
	liy.push_front(20);
	liy.print_all(cout);

	List<string, Your_allocator> lsy;
	lsy.push_front("string");
	lsy.push_front("test");
	lsy.print_all(cout);
}
