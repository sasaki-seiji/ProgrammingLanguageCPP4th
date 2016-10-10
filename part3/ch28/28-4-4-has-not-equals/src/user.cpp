/*
 * user.cpp
 *
 *  Created on: 2016/10/10
 *      Author: sasaki
 */


#include "Vector.h"
#include "has_not_equals.h"
#include <iostream>

template<bool B, typename T=void>
using Enable_if = typename std::enable_if<B,T>::type;

template<typename Iter, typename Val>
Enable_if<Has_not_equals<Iter>(),Iter> find(Iter first, Iter last, Val v)
{
	std::cout << "use !=\n";
	while (first!=last && !(*first==v))
		++first;
	return first;
}

template<typename Iter, typename Val>
Enable_if<!Has_not_equals<Iter>(),Iter> find(Iter first, Iter last, Val v)
{
	std::cout << "not use !=\n";
	while (!(first==last) && !(*first==v))
		++first;
	return first;
}

// add main

int main()
{
	Vector<int> vi { 2, 3, 10, 5, 7, 8};
	Vector_iter<int> it1 = find(vi.begin(),vi.end(),7);
	Vector_iter<int> it2 = find(vi.begin(),vi.end(),9);
	std::cout << "Has_not_equals<Vector_iter<int>>(): " << Has_not_equals<Vector_iter<int>>() << '\n';
	std::cout << "it1!=it2: " << (it1!=it2) << '\n';
	if (it1!=vi.end()) std::cout << "found: " << *it1 << '\n';
	if (it2!=vi.end()) std::cout << "found: " << *it2 << '\n';

}
