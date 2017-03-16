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
ostream& operator<<(ostream& os, const Vector<T>& v)
{
	os << '[';
	for (size_t i = 0 ; i != v.size(); ++i)
		os << v[i] << ',';
	os << "]";
	return os;
}

template<typename T>
Vector<T> make_vector(size_t n, const T& val = T{})
{
	Vector<T> v(n, val);
	return v;
}

int main()
{
	Vector<int> vi(10, 123);
	Vector<string> vs(10, "abc");
	cout << "vi: " << vi << '\n'<< flush;
	cout << "vs: " << vs << '\n'<< flush;

	Vector<int> vi2(15, 456);
	Vector<string> vs2(15, "xyz");
	cout << "vi2: " << vi2 << '\n'<< flush;
	cout << "vs2: " << vs2 << '\n'<< flush;

	// assign
	vi2 = vi;
	vs2 = vs;
	cout << "vi2(assigned): " << vi2 << '\n'<< flush;
	cout << "vs2(assigned): " << vs2 << '\n'<< flush;
}
