/*
 * gslice.cpp
 *
 *  Created on: 2017/01/14
 *      Author: sasaki
 */


#include <valarray>
#include <iostream>
using namespace std;

size_t gslice_index(const gslice& s, size_t i, size_t j)
{
	return s.start() + i*s.stride()[0] + j*s.stride()[1];
}

valarray<size_t> lengths {3,2};
valarray<size_t> strides {3,1};

void f()
{
	gslice s(0,lengths,strides);

	for (int i=0; i<3; ++i)
		for (int j=0; j<2; ++j)
			cout << "(" << i << "," << j << ")->"
				<< gslice_index(s,i,j) << "; ";
	cout << endl;
}

void f(valarray<float>& v)
{
	gslice m(0,lengths,strides);
	v[m] = 9.9;
}

template<typename T>
ostream& operator<<(ostream& os, const valarray<T>& v)
{
	for (auto x : v)
		os << x << ' ';
	return os;
}


int main()
{
	f();

	valarray<float> v {
		0.1, 0.2, 0.3,
		1.1, 1.2, 1.3,
		2.1, 2.2, 2.3,
		3.1, 3.2, 3.3
	};
	cout << "before: " << v << endl;
	f(v);
	cout << "after:  " << v << endl;

}
