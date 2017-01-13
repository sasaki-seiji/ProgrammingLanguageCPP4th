/*
 * slice_array.cpp
 *
 *  Created on: 2017/01/13
 *      Author: sasaki
 */


#include <valarray>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const valarray<T>& v)
{
	for (auto x : v)
		os << x << ' ';
	return os;
}

void f(valarray<double>& d)
{
	const slice_array<double>& v_even = d[slice(0, d.size()/2+d.size()%2, 2)];
	const slice_array<double>& v_odd = d[slice(1, d.size()/2, 2)];

	v_even *= v_odd;
	v_odd = 0;
}

slice_array<double> row(valarray<double>& d, int i)
{
	slice_array<double> v = d[slice(0, d.size()/2, 1)];
	return d[slice((i%2)*d.size()/2, d.size()/2, 1)];
}

int main()
{
	valarray<double> v {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
	f(v);
	cout << "v: " << v << endl;

	valarray<double> row1 = row(v,1);
	cout << "row(v,1): " << row1 << endl;
}
