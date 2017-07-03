/*
 * test_matrix_addition.cpp
 *
 *  Created on: 2017/07/03
 *      Author: sasaki
 */



#include "Matrix.h"

void matrix_addition()
{
	cout << "-- matrix_addition() --\n";

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
