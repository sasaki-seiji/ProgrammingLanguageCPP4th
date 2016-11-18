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


void test_Matrix_mixed_add()
{
	cout << "--- test_Matrix_mixed_add() --\n";

	Matrix<double, 2> md = { { 1, 2 }, { 3, 4 } };
	Matrix<complex<double>, 2> mc = {
			{ complex<double>(0, 1), complex<double>(0, 2) },
			{ complex<double>(1, 3), complex<double>(1, 4) }
	};
	cout << "md: " << md << endl;
	cout << "mc: " << mc << endl;

	Matrix<complex<double>, 2> mc2 = mc + md;
	cout << "mc2: " << mc2 << endl;

	Matrix<long double, 2> mld = { { 1, 2 }, { 3, 4 } };
	Matrix<Quad, 2> mqd = {	{ 10, 20 }, { 30, 40 } };
	cout << "mld: " << mld << endl;
	cout << "mqd: " << mqd << endl;

	Matrix<Quad, 2> mqd2 = mld + mqd;
	cout << "mqd2: " << mqd2 << endl;
}

void test_Matrix_addassign_Matrix()
{
	cout << "--- test_Matrix_addassign_Matrix() --\n";

	Matrix<double, 2> m1 = { { 1, 2 }, { 3, 4 } };
	Matrix<double, 2> m2 = { { 5, 6 }, { 7, 8 } };
	cout << "m1: " << m1 << endl;
	cout << "m2: " << m2 << endl;

	m1 += m2;
	cout << "m1: " << m1 << endl;
}

void test_Matrix_addassign_Matrix_ref()
{
	cout << "--- test_Matrix_addassign_Matrix_ref() --\n";

	Matrix<double, 2> m1 = { { 1, 2 }, { 3, 4 } };
	Matrix<double, 2> m2 = { { 5, 6 }, { 7, 8 }, { 9, 10 } };
	Matrix_ref<double, 2> mr2 = m2(slice(1), slice(0));

	cout << "m1: " << m1 << endl;
	cout << "m2: " << m2 << endl;
	cout << "mr2: " << mr2 << endl;

	m1 += mr2;
	cout << "m1: " << m1 << endl;
}

void test_Matrix_add_Matrix()
{
	cout << "--- test_Matrix_add_Matrix() --\n";

	Matrix<double, 2> m1 = { { 1, 2 }, { 3, 4 } };
	Matrix<double, 2> m2 = { { 5, 6 }, { 7, 8 } };
	cout << "m1: " << m1 << endl;
	cout << "m2: " << m2 << endl;

	auto m3 = m1 + m2;
	cout << "m3: " << m3 << endl;
}

void test_Matrix_add_Matrix_ref()
{
	cout << "--- test_Matrix_add_Matrix_ref() --\n";

	Matrix<double, 2> m1 = { { 1, 2 }, { 3, 4 } };
	Matrix<double, 2> m2 = { { 5, 6 }, { 7, 8 }, { 9, 10 } };
	Matrix_ref<double, 2> mr2 = m2(slice(1), slice(0));

	cout << "m1: " << m1 << endl;
	cout << "m2: " << m2 << endl;
	cout << "mr2: " << mr2 << endl;

	auto m3 = m1 + mr2;
	cout << "m3: " << m3 << endl;
}

void test_Matrix_subassign_Matrix()
{
	cout << "--- test_Matrix_subassign_Matrix() --\n";

	Matrix<double, 2> m1 = { { 1, 2 }, { 3, 4 } };
	Matrix<double, 2> m2 = { { 5, 6 }, { 7, 8 } };
	cout << "m1: " << m1 << endl;
	cout << "m2: " << m2 << endl;

	m1 -= m2;
	cout << "m1: " << m1 << endl;
}

