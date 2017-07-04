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

	cout << "md1: " << md1 << endl;
	cout << "md2: " << md2 << endl;
	cout << "mi1: " << mi1 << endl;

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

	cout << "md1: " << md1 << endl;
	cout << "md2: " << md2 << endl;

	cout << "md1 + md2: " << md1+md2 << endl;
	cout << "md1 - md2: " << md1-md2 << endl;
}

void matrixT_add_matrixT2()
{
	cout << "-- matrixT_add_matrixT2() --\n";

	Matrix<double, 2> md { { 1.1, 2.2 }, { 3.3, 4.4 } };
	Matrix<long double, 2> mld { {-1.0, 2.0}, { -3.0, 4.0 } };

	cout << "md: " << md << endl;
	cout << "mld: " << mld << endl;

	cout << "md + mld: " << md+mld << endl;
	cout << "mld - md: " << mld-md << endl;

	Matrix<complex<double>, 2> mc {
		{ {-1.0, 0}, {0, 2.0} },
		{ {-3.0, 0}, {0, 4.0} }
	};
	cout << "mc.desc: " << mc.descriptor() << endl;
	cout << "mc: " << mc << endl;
	cout << "md + mc: " << md+mc << endl;
	cout << "mc - md: " << mc-md << endl;
}
