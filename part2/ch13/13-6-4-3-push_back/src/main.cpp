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
	Vector<int> vi(0);
	Vector<string> vs(0);

	for (int i = 0; i < 10; ++i) {
		vi.push_back(i*i);
		vs.push_back("xy");
	}
	cout << "vi: " << vi << ", capacity = " << vi.capacity() << '\n'<< flush;
	cout << "vs: " << vs << ", capacity = " << vs.capacity() << '\n'<< flush;
}
