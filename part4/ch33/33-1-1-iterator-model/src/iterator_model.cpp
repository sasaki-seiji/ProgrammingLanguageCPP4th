/*
 * iterator_model.cpp
 *
 *  Created on: 2016/12/03
 *      Author: sasaki
 */

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void f(const vector<int>& v, int x)
{
	auto p = find(v.begin(), v.end(), x);

	if (p!=v.end()) {
		cout << "found: " << x << endl;
	}
	else {
		cout << "not found: " << x << endl;
	}
}

template<typename Iter>
void forward(Iter p, int n)
{
	while (n>0)
		*p++ = --n;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto& x : v)
		os << x << ", ";
	return os;
}

void user()
{
	vector<int> v(10);
	forward(v.begin(), v.size());
	cout << "v: " << v << endl;
	//forward(v.begin(), 1000);	// crash
	//cout << "v: " << v << endl;
}

int main()
{
	vector<int> v {1,2,3,4,5,6,7,8,9};
	f(v,7);

	user();
}
