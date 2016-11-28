/*
 * mismatch.cpp
 *
 *  Created on: 2016/11/28
 *      Author: sasaki
 */


#include "concept.h"
using namespace Estd;

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

template<typename In, typename In2, typename Pred = equal_to<Value_type<In>>>
pair<In, In2> my_mismatch(In first, In last, In2 first2, Pred p ={})
{
	while (first != last && p(*first,*first2)) {
		++first;
		++first2;
	}
	return {first,first2};
}

int main()
{
	vector<int> v1 { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
				v2 { 1, 2, 3, 4, 5, 10, 11, 12, 13, 14 };

	using iter = vector<int>::iterator;
	pair<iter,iter> p1 = mismatch(v1.begin(), v1.end(), v2.begin()),
					p2 = my_mismatch(v1.begin(), v2.end(), v2.begin());
	cout << "*p1.first: " << *p1.first << endl;
	cout << "*p1.second: " << *p1.second << endl;
	cout << "*p2.first: " << *p2.first << endl;
	cout << "*p2.second: " << *p2.second << endl;
}
