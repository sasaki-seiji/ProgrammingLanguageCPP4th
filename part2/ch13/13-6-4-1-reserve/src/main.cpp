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
	cout << "vi(original): " << vi << ", capacity = " << vi.capacity() << '\n'<< flush;
	cout << "vs(original): " << vs << ", capacity = " << vs.capacity() << '\n'<< flush;

	vi.reserve(100);
	vs.reserve(100);
	cout << "vi(reserved): " << vi << ", capacity = " << vi.capacity() << '\n'<< flush;
	cout << "vs(reserved): " << vs << ", capacity = " << vs.capacity() << '\n'<< flush;
}
