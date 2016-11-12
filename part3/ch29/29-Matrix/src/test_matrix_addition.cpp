/*
 * matrix_addition.cpp
 *
 *  Created on: 2016/11/01
 *      Author: sasaki
 */


#include "Matrix.h"
#include <iostream>
#include <complex>
using namespace std;

struct Quad {
	long double ld;
	Quad(long double q) : ld{q} { }
	Quad& operator+=(Quad q) { ld += q.ld; return *this; }
};

ostream& operator<<(ostream& os, Quad q)
{
	os << "Quad(" << q.ld << ")";
	return os;
}

namespace std {

	template<>
	struct common_type<Quad,long double> {
		using type = Quad;
	};

}

void test_mixed_add()
{
	cout << "--- test_mixed_add() --\n";

	Matrix<double, 2> md = { { 1, 2 }, { 3, 4 } };
	Matrix<complex<double>, 2> mc = {
			{ complex<double>(0, 1), complex<double>(0, 2) },
			{ complex<double>(1, 3), complex<double>(1, 4) }
	};
	Matrix<complex<double>, 2> mc2 = mc + md;
	cout << "mc2: " << mc2 << endl;

	Matrix<long double, 2> mld = { { 1, 2 }, { 3, 4 } };
	Matrix<Quad, 2> mqd = {	{ 10, 20 }, { 30, 40 } };
	Matrix<Quad, 2> mqd2 = mld + mqd;
	cout << "mqd2: " << mqd2 << endl;
}
