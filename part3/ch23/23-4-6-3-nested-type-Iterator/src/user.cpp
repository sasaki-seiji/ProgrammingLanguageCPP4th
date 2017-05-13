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

template<typename Iter, typename T>
Iter find(Iter b, Iter e, const T& v)
{
	for ( ;b != e; ++b) {
		if (*b == v) return b;
	}
	return e;
}


void fct(List<int, My_allocator>::Iterator b, List<int, My_allocator>::Iterator e)
{
	auto p = find(b,e,17);

	if (p!=e)
		cout << "found: 17\n";
	else
		cout << "not found: 17\n";
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
	lim.push_front(10);
	lim.push_front(17);
	lim.push_front(20);

	List<int, Your_allocator> liy;
	liy.push_front(10);
	liy.push_front(20);

	user(lim, liy);
}
