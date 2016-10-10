/*
 * user.cpp
 *
 *  Created on: 2016/10/10
 *      Author: sasaki
 */


#include "Vector.h"
#include "Vector2.h"
#include <iostream>
#include <type_traits>

template<bool B, typename T=void>
using Enable_if = typename std::enable_if<B,T>::type;

template<typename T>
auto operator!=(const T& a, const T& b) -> decltype(!(a==b))
{
	std::cout << "::operator!=(const T&,const T&)\n";
	return !(a==b);
}

template<typename Iter, typename Val>
Iter find(Iter first, Iter last, Val v)
{
	std::cout << "find(Iter,Iter)\n";

	while (first!=last && !(*first==v))
		++first;
	return first;
}

// add main

int main()
{
	Vector<int> v1 { 2, 3, 10, 5, 7, 8};
	Vector_iter<int> it11 = find(v1.begin(),v1.end(),7);
	Vector_iter<int> it12 = find(v1.begin(),v1.end(),9);
	if (it11!=v1.end()) std::cout << "found: " << *it11 << '\n';
	if (it12!=v1.end()) std::cout << "found: " << *it12 << '\n';

	Vector2<int> v2 { 2, 3, 10, 5, 7, 8};
	Vector2_iter<int> it21 = find(v2.begin(),v2.end(),7);
	Vector2_iter<int> it22 = find(v2.begin(),v2.end(),9);
	if (!(it21==v2.end())) std::cout << "found: " << *it21 << '\n';
	if (!(it22==v2.end())) std::cout << "found: " << *it22 << '\n';
}
