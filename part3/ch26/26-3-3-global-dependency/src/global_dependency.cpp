/*
 * global_dependency.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename T>
void print_sorted(vector<T>& v)
{
	sort(v.begin(), v.end());
	for (const auto& x : v)
		cout << x << '\n';
}

void use(vector<string>& vec)
{
	print_sorted(vec);
}

template<typename T, typename S>
void print_sorted(vector<T>& v, S sort, ostream& os)
{
	sort(v.begin(), v.end());
	for (const auto& x : v)
		os << x << '\n';
}

void fct(vector<string>& vec)
{
	using Iter = decltype(vec.begin());
	print_sorted(vec, std::sort<Iter>, std::cout);
}

// add main

int main()
{
	vector<string> vs { "this", "is", "a", "string", "vector" };

	cout << "-- depend global info\n";
	use(vs);
	cout << "-- not depend to global info\n";
	fct(vs);
}
