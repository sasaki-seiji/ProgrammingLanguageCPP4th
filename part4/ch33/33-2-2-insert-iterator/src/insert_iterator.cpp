/*
 * insert_iterator.cpp
 *
 *  Created on: 2016/12/03
 *      Author: sasaki
 */


#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto& x : v)
		os << x << ',';
	return os;
}

void f(vector<int>& vi)
{
	fill_n(vi.begin(), 200, 7);
}

void g(vector<int>& vi)
{
	fill_n(back_inserter(vi), 200, 7);
}

int main()
{
	vector<int> v;
	for (size_t i = 0; i < 200; ++i)
		v.push_back(i);

	cout << "v: " << v << endl;
	f(v);
	cout << "after f(v), v: " << v << endl;

	vector<int> v2;
	g(v2);
	cout << "after g(v2), v2: " << v2 << endl;
}

