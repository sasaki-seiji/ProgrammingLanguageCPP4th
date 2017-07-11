/*
 * test_matrix_addition.cpp
 *
 *  Created on: 2017/07/03
 *      Author: sasaki
 */



#include "Matrix.h"
#include <complex>
using namespace std;

void add_assign_matrix()
{
	cout << "-- add_assign_matrix() --\n";

	Matrix<double, 2> md1 { { 1.1, 2.2 }, { 3.3, 4.4 } };
	Matrix<double, 2> md2 { {-1.0, 2.0 }, {-3.0, 4.0} };
	Matrix<int, 2> mi1 { {-1,2}, {-3,4} };

	cout << "Matrix<double, 2> md1: " << md1 << endl;
	cout << "Matrix<double, 2> md2: " << md2 << endl;
	cout << "Matrix<int, 2> mi1: " << mi1 << endl;

	md1 += md2;
	cout << "md1 += md2; md1: " << md1 << endl;

	md1 += mi1;
	cout << "md1 += mi1; md1: " << md1 << endl;

	md1 -= mi1;
	cout << "md1 -= mi1; md1: " << md1 << endl;

	md1 -= md2;
	cout << "md1 -= md2; md1: " << md1 << endl;
}

void matrix_add_matrix()
{
	cout << "-- matrix_add_matrix() --\n";

	Matrix<double, 2> md1 { { 1.1, 2.2 }, { 3.3, 4.4 } };
	Matrix<double, 2> md2 { {-1.0, 2.0 }, {-3.0, 4.0} };

	cout << "Matrix<double, 2> md1: " << md1 << endl;
	cout << "Matrix<double, 2> md2: " << md2 << endl;

	cout << "md1 + md2: " << md1+md2 << endl;
	cout << "md1 - md2: " << md1-md2 << endl;
}

void matrixT_add_matrixT2()
{
	cout << "-- matrixT_add_matrixT2() --\n";

	Matrix<double, 2> md { { 1.1, 2.2 }, { 3.3, 4.4 } };
	Matrix<long double, 2> mld { {-1.0, 2.0}, { -3.0, 4.0 } };

	cout << "Matrix<double, 2> md: " << md << endl;
	cout << "Matrix<long double, 2> mld: " << mld << endl;

	cout << "md + mld: " << md+mld << endl;
	cout << "mld - md: " << mld-md << endl;

	Matrix<complex<double>, 2> mc {
		{ {-1.0, 0}, {0, 2.0} },
		{ {-3.0, 0}, {0, 4.0} }
	};
	cout << "Matrix<complex<double>, 2> mc: " << mc << endl;
	cout << "mc.desc: " << mc.descriptor() << endl;
	cout << "md + mc: " << md+mc << endl;
	cout << "mc - md: " << mc-md << endl;
}

struct Quad {
	long double ld;
	Quad(long double ld) : ld{ld} { }
	Quad& operator+=(Quad a) { ld += a.ld; return *this; }
	Quad& operator-=(Quad a) { ld -= a.ld; return *this; }
};
Quad operator+(Quad a, Quad b) { Quad res{a}; res += b; return res; }
Quad operator-(Quad a, Quad b) { Quad res{a}; res -= b; return res; }
ostream& operator<<(ostream& os, Quad q) { 	return os << q.ld; }

void matrixld_add_matrixQuad()
{
	cout << "-- matrixld_add_matrixQuad() --\n";

	Matrix<long double, 2> mld { {-1.0, 2.0}, { -3.0, 4.0 } };
	Matrix<Quad, 2> mq { {1.1, 2.2}, {3.3, 4.4} };

	cout << "Matrix<long double, 2> mld: " << mld << endl;
	cout << "Matrix<Quad, 2> mq: " << mq << endl;

	cout << "mld + mq: " << mld+mq << endl;
	cout << "mq - mld: " << mq-mld << endl;
}

void matrix_addition_all()
{
	cout << "@@ 29.4.2. matrix addtion @@\n";

	add_assign_matrix();
	matrix_add_matrix();
	matrixT_add_matrixT2();
	matrixld_add_matrixQuad();
}

