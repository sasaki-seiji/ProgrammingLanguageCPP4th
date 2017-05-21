/*
 * user.cpp
 *
 *  Created on: 2016/10/10
 *      Author: sasaki
 */


#include "Vector.h"
#include "List.h"
#include <iostream>

#include "my_find.h"
using namespace std;

// add main

int main()
{
	cout << boolalpha;

	cout << "Has_not_equal<Vector<int>::iterator>(): " << Has_not_equal<Vector<int>::iterator>() << '\n';
	Vector<int> v { 2, 3, 10, 5, 7, 8};
	Vector<int>::iterator vi1 = my_find(v.begin(),v.end(),7);
	Vector<int>::iterator vi2 = my_find(v.begin(),v.end(),9);
	cout << "vi1!=vi2: " << (vi1!=vi2) << '\n';
	if (vi1!=v.end()) cout << "found: " << *vi1 << '\n';
	if (vi2!=v.end()) cout << "found: " << *vi2 << '\n';

	cout << "Has_not_equal<List<int>::iterator>(): " << Has_not_equal<List<int>::iterator>() << endl;
	List<int> list { 2, 3, 10, 5, 7, 8 };
	List<int>::iterator li1 = my_find(list.begin(), list.end(), 7);
	List<int>::iterator li2 = my_find(list.begin(), list.end(), 9);
	if (!(li1==list.end())) cout << "found: " << *li1 << '\n';
	if (!(li2==list.end())) cout << "found: " << *li2 << '\n';
}
