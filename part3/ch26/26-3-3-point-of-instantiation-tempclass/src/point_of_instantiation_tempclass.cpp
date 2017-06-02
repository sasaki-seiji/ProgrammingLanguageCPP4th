/*
 * point_of_instantiation_tempclass.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// point of instantiation of template class and member function

template<typename T>
class Container {
	vector<T> v;
public:
	void sort() { std::sort(v.begin(), v.end()); }

	size_t size() const { return v.size(); }
	void push_back(const T& x) { v.push_back(x); }
	T& operator[](size_t i) { return v[i]; }
};

void f()
{
	cout << "-- f() --\n";

	Container<int> c;
	c.push_back(10); c.push_back(5); c.push_back(20); c.push_back(1);

	c.sort();
	for (size_t i = 0; i!=c.size(); ++i)
		cout << c[i] << ' ';
	cout << '\n';
}

// instantiation for local type

void fff()
{
	cout << "-- fff() --\n";

	struct S { int a, b; };
	vector<S> vs { {1,2}, {2,3}, {4,5} };
	for (auto& x : vs)
		cout << x.a << ", " << x.b << '\n';
}

// add main

int main()
{
	f();
	fff();
}
