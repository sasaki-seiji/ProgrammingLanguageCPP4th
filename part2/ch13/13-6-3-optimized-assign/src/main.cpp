/*
 * main.cpp
 *
 *  Created on: 2016/05/21
 *      Author: sasaki
 */

#include <iostream>
#include <string>
using namespace std;
#include "vector.h"

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << '[';
	for (size_t i = 0 ; i != v.size(); ++i)
		os << v[i] << ',';
	os << "]";
	return os;
}

template<typename T>
vector<T> make_vector(size_t n, const T& val = T{})
{
	vector<T> v(n, val);
	return v;
}

int main()
{
	vector<int> vi(10, 123);
	vector<string> vs(10, "abc");
	cout << "vi: " << vi << '\n'<< flush;
	cout << "vs: " << vs << '\n'<< flush;

	vector<int> vi2(15, 456);
	vector<string> vs2(15, "xyz");
	cout << "vi2: " << vi2 << '\n'<< flush;
	cout << "vs2: " << vs2 << '\n'<< flush;

	// assign
	vi2 = vi;
	vs2 = vs;
	cout << "vi2(assigned): " << vi2 << '\n'<< flush;
	cout << "vs2(assigned): " << vs2 << '\n'<< flush;
}
