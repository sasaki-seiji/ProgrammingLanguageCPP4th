/*
 * user.cpp
 *
 *  Created on: 2016/10/10
 *      Author: sasaki
 */


#include "Vector.h"
#include "Vector2.h"
#include <iostream>

#include "my_find.h"
using namespace std;

// add main

int main()
{
	cout << boolalpha;

	cout << "Has_not_equal<Vector_iter<int>>(): " << Has_not_equal<Vector_iter<int>>() << '\n';
	Vector<int> v1 { 2, 3, 10, 5, 7, 8};
	Vector_iter<int> it11 = my_find(v1.begin(),v1.end(),7);
	Vector_iter<int> it12 = my_find(v1.begin(),v1.end(),9);
	cout << "it11!=it12: " << (it11!=it12) << '\n';
	if (it11!=v1.end()) cout << "found: " << *it11 << '\n';
	if (it12!=v1.end()) cout << "found: " << *it12 << '\n';

	cout << "Has_not_equal<Vector2_iter<int>>(): " << Has_not_equal<Vector2_iter<int>>() << '\n';
	Vector2<int> v2 { 2, 3, 10, 5, 7, 8};
	Vector2_iter<int> it21 = my_find(v2.begin(),v2.end(),7);
	Vector2_iter<int> it22 = my_find(v2.begin(),v2.end(),9);
	if (!(it21==v2.end())) cout << "found: " << *it21 << '\n';
	if (!(it22==v2.end())) cout << "found: " << *it22 << '\n';
}
