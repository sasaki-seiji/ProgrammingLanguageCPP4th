/*
 * slice.cpp
 *
 *  Created on: 2017/01/13
 *      Author: sasaki
 */


#include <valarray>
#include <iostream>
#include "Slice_iter.h"
using namespace std;

int main()
{
#if 0
	valarray<int> v {
		{00,01,02,03},
		{10,11,12,13},
		{20,21,23,24}
	};	// error: no matching function for call to ‘std::valarray<int>::valarray(<brace-enclosed initializer list>)’
#else
	valarray<int> v {
		00,01,02,03,
		10,11,12,13,
		20,21,23,24
	};
#endif

	for (int x : v) cout << x << ' ';
	cout << endl;

	Slice_iter<int> p {&v, slice(4,4,1)};
	for ( ; p!=p.end(); ++p) cout << *p << ' ';
	cout << endl;

	Slice_iter<int> q {&v, slice(2,3,4)};
	for ( ; q!=q.end(); ++q) cout << *q << ' ';
	cout << endl;

}
