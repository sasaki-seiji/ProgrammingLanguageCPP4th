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
	cout << "vi: " << vi << '\n';
	cout << "vs: " << vs << '\n';

	// copy
	Vector<int> vi2{vi};
	Vector<string> vs2{vs};
	cout << "vi2(copied): " << vi2 << '\n';
	cout << "vs2(copied): " << vs2 << '\n';

	// move
	Vector<int> vi3 = make_vector(10, 456);
	Vector<string> vs3 = make_vector<string>(10, "xyz");
	cout << "vi3(moved): " << vi3 << '\n';
	cout << "vs3(moved): " << vs3 << '\n';

	// move construct and move assign
	swap(vi2, vi3);
	cout << "vi2(swapped): " << vi2 << endl;
	cout << "vi3(swapped): " << vi3 << endl;
}
