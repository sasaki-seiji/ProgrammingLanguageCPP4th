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
	cout << "vi: " << vi << '\n';
	cout << "vs: " << vs << '\n';

	// copy
	vector<int> vi2{vi};
	vector<string> vs2{vs};
	cout << "vi2(copied): " << vi2 << '\n';
	cout << "vs2(copied): " << vs2 << '\n';

	// move
	vector<int> vi3 = make_vector(10, 456);
	vector<string> vs3 = make_vector<string>(10, "xyz");
	cout << "vi3(moved): " << vi3 << '\n';
	cout << "vs3(moved): " << vs3 << '\n';
}
