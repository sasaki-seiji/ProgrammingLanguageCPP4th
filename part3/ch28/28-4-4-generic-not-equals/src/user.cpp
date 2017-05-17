/*
 * user.cpp
 *
 *  Created on: 2016/10/10
 *      Author: sasaki
 */


#include "Vector.h"
#include "Vector2.h"
#include "my_find.h"
#include <iostream>
#include <type_traits>
using namespace std;

template<bool B, typename T=void>
using Enable_if = typename std::enable_if<B,T>::type;

template<typename T>
auto operator!=(const T& a, const T& b) -> decltype(!(a==b))
{
	std::cout << "::operator!=(const T&,const T&)\n";
	return !(a==b);
}

// add main

int main()
{
	Vector<int> v1 { 2, 3, 10, 5, 7, 8};
	Vector_iter<int> it11 = my_find(v1.begin(),v1.end(),7);
	if (it11!=v1.end()) cout << "found: " << *it11 << '\n';
	Vector_iter<int> it12 = my_find(v1.begin(),v1.end(),9);
	if (it12!=v1.end()) cout << "found: " << *it12 << '\n';

	Vector2<int> v2 { 2, 3, 10, 5, 7, 8};
	Vector2_iter<int> it21 = my_find(v2.begin(),v2.end(),7);
	if (!(it21==v2.end())) cout << "found: " << *it21 << '\n';
	Vector2_iter<int> it22 = my_find(v2.begin(),v2.end(),9);
	if (!(it22==v2.end())) cout << "found: " << *it22 << '\n';
}
