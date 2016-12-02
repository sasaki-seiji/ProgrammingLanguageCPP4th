/*
 * binary_search.cpp
 *
 *  Created on: 2016/12/02
 *      Author: sasaki
 */


#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void f(vector<int>& c)
{
	if (binary_search(c.begin(), c.end(), 7)) {
		cout << "found: 7\n";
	}
}

void g(vector<int>& c)
{
	auto p = find(c.begin(), c.end(), 7);
	if (p!=c.end()) cout << "find - *p: " << *p << endl;

	auto q = lower_bound(c.begin(), c.end(), 7);
	if (q!=c.end()) cout << "lower_bound - *q: " << *q << endl;
}

int main()
{
	vector<int> v { 1,2,3,4,5,6,7,8,9,10};
	f(v);
	g(v);
}
