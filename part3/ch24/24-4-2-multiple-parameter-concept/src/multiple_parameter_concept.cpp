/*
 * multiple_parameter_concept.cpp
 *
 *  Created on: 2016/10/23
 *      Author: sasaki
 */

#include "equality_comparable.h"
#include "input_iterator.h"
#include "iterator_traits.h"
using namespace Estd;

#include <forward_list>
#include <iostream>
using namespace std;

template<typename Iter, typename Val>
Iter find(Iter b, Iter e, Val x)
{
	static_assert(Input_iterator<Iter>(), "find() requires an input iterator");
	static_assert(Equality_comparable<Value_type<Iter>,Val>(),
			"find()'s iterator and value arguments must match");

	while (b!=e) {
		if (*b==x) return b;
		++b;
	}
	return b;
}

// add main

int main()
{
	std::forward_list<int> fl{5,1,4,3,2};
	auto it = find(fl.begin(), fl.end(), 3);
	std::cout << "*it: " << *it << '\n';

	//auto it2 = find(fl.begin(), fl.end(), "abc");
		// error: static assertion failed: find()'s iterator and value arguments must match
}



