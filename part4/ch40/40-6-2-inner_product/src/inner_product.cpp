/*
 * inner_product.cpp
 *
 *  Created on: 2017/01/14
 *      Author: sasaki
 */


#include <numeric>
#include <valarray>
#include "Matrix.h"
using namespace std;

valarray<double> operator*(const Matrix<double,2>& m, valarray<double>& v)
{
	valarray<double> res(m.extent(0));
	for (size_t i=0; i<m.extent(1); i++) {
		auto ri = m.row(i);
		res[i] = inner_product(ri.begin(), ri.end(), &v[0], double(0));
	}
	return res;
}

valarray<double> operator*(valarray<double>& v, const Matrix<double,2>& m)
{
	valarray<double> res(m.extent(1));
	for (size_t i=0; i<m.extent(0); i++) {
		auto ci = m.col(i);
		res[i] = inner_product(ci.begin(), ci.end(), &v[0], double(0));
	}
	return res;
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
	Matrix<double,2> m = {
			{1.1, 1.2, 1.3},
			{2.1, 2.2, 2.3},
			{3.1, 3.2, 3.3}
	};
	valarray<double> v { 1, 1, 1 };

	cout << "m*v: " << m*v << endl;
	cout << "v*m: " << v*m << endl;
}
