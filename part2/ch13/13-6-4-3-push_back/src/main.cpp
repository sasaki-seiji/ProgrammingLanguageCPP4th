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
	vector<int> vi(0);
	vector<string> vs(0);

	for (int i = 0; i < 20; ++i) {
		vi.push_back(i*i);
		vs.push_back("xy");
	}
	cout << "vi: " << vi << ", capacity = " << vi.capacity() << '\n'<< flush;
	cout << "vs: " << vs << ", capacity = " << vs.capacity() << '\n'<< flush;
}
