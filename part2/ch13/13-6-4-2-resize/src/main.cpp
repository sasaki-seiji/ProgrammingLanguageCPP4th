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
	cout << "vi(original): " << vi << ", capacity = " << vi.capacity() << '\n'<< flush;
	cout << "vs(original): " << vs << ", capacity = " << vs.capacity() << '\n'<< flush;

	vi.resize(15, 456);
	vs.resize(5);
	cout << "vi(resized): " << vi << ", capacity = " << vi.capacity() << '\n'<< flush;
	cout << "vs(resized): " << vs << ", capacity = " << vs.capacity() << '\n'<< flush;
}
