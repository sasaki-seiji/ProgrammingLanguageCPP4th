/*
 * iterator.cpp
 *
 *  Created on: 2016/11/25
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

void test_iterator(vector<int>& v)
{
	for (auto& x : v)
		cout << x << '\n';

	for (auto p = v.begin(); p!=v.end(); ++p) {
		if (p!=v.begin() && *(p-1)==*p)
			cout << "duplicate " << *p << '\n';
	}

	for (auto p = v.cbegin(); p!=v.cend(); ++p) {
		if (p!=v.cbegin() && *(p-1)==*p)
			cout << "duplicate " << *p << '\n';
	}

	auto beg = v.cbegin();
	auto end = v.cend();
	for (auto p = beg; p!=end; ++p) {
		if (p!=beg && *(p-1)==*p)
			cout << "duplicate " << *p << '\n';
	}

}

int main()
{
	vector<int> v { 1, 2, 3, 3, 4, 5, 6, 6 };
	test_iterator(v);
}
