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
	lim.add_head(10);
	lim.add_head(20);
	lim.print_all(cout);

	List<int, Your_allocator> liy;
	liy.add_head(10);
	liy.add_head(20);
	liy.print_all(cout);

}
