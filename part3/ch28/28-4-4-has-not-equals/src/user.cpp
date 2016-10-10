/*
 * user.cpp
 *
 *  Created on: 2016/10/10
 *      Author: sasaki
 */


#include "Vector.h"
#include "Vector2.h"
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
	Vector<int> v1 { 2, 3, 10, 5, 7, 8};
	Vector_iter<int> it11 = find(v1.begin(),v1.end(),7);
	Vector_iter<int> it12 = find(v1.begin(),v1.end(),9);
	std::cout << "Has_not_equals<Vector_iter<int>>(): " << Has_not_equals<Vector_iter<int>>() << '\n';
	std::cout << "it11!=it12: " << (it11!=it12) << '\n';
	if (it11!=v1.end()) std::cout << "found: " << *it11 << '\n';
	if (it12!=v1.end()) std::cout << "found: " << *it12 << '\n';

	Vector2<int> v2 { 2, 3, 10, 5, 7, 8};
	Vector2_iter<int> it21 = find(v2.begin(),v2.end(),7);
	Vector2_iter<int> it22 = find(v2.begin(),v2.end(),9);
	std::cout << "Has_not_equals<Vector2_iter<int>>(): " << Has_not_equals<Vector2_iter<int>>() << '\n';
	if (!(it21==v2.end())) std::cout << "found: " << *it21 << '\n';
	if (!(it22==v2.end())) std::cout << "found: " << *it22 << '\n';
}
