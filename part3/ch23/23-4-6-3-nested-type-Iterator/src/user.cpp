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


void fct(List<int, My_allocator>::Iterator b, List<int, My_allocator>::Iterator e)
{
	//auto p = find(b,e,17);
		// error: no matching function for call to 'find(List<int, My_allocator>::Iterator&, List<int, My_allocator>::Iterator&, int)'
		// note:   couldn't deduce template parameter 'A'
	auto p = find<int,My_allocator>(b,e,17);

	if (p!=e)
		cout << "found\n";
	else
		cout << "not found\n";
}

void user(List<int, My_allocator>& lm, List<int, Your_allocator>& ly)
{
	fct(lm.begin(), lm.end());
	//fct(ly.begin(), ly.end());
		// error: could not convert '(& ly)->List<T, Allocator>::begin<int, Your_allocator>()' from 'List<int, Your_allocator>::Iterator' to 'List<int, My_allocator>::Iterator'
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
