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


void fct(Iterator<int> b, Iterator<int> e)
{
	auto p = find(b,e,17);

	if (p!=e)
		cout << "found\n";
	else
		cout << "not found\n";
}

void user(List<int, My_allocator>& lm, List<int, Your_allocator>& ly)
{
	fct(lm.begin(), lm.end());
	fct(ly.begin(), ly.end());
}

int main()
{
	List<int, My_allocator> lim;
	lim.add_head(10);
	lim.add_head(17);
	lim.add_head(20);

	List<int, Your_allocator> liy;
	liy.add_head(10);
	liy.add_head(20);

	user(lim, liy);
}
