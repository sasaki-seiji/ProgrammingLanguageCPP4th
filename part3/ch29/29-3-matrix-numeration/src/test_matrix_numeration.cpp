/*
 * test_matrix_numeration.cpp
 *
 *  Created on: 2017/07/02
 *      Author: sasaki
 */


#include "Matrix.h"


void test_scalar_multiply()
{
	cout << "-- test_scalar_multipy() --\n";

	Matrix<int,2> m1 {{1,2,3},{4,5,6}};

	cout << "Matrix<int,2> m1: " << m1 << endl;
	m1 *= 2;
	cout << "m1 *= 2; m1: " << m1 << endl;
}


void test_matrix_addition()
{
	cout << "-- test_matrix_addition() --\n";

	Matrix<int,2> m1 {{1,2,3},{4,5,6}};
	Matrix<int,2> m2 {m1};

	cout << "Matrix<int,2> m1: " << m1 << endl;
	cout << "Matrix<int,2> m2: " << m2 << endl;
	Matrix<int,2> m3 = m1+m2;
	cout << "Matrix<int,2> m3 = m1+m2; m3: " << m3 << endl;
}


void test_matrix_product()
{
	cout << "-- test_matrix_product() --\n";

	Matrix<int,2> m1 {{1,2,3},{4,5,6}};
	Matrix<int,2> m4 {{1,2},{3,4},{5,6}};

	cout << "Matrix<int,2> m1: " << m1 << endl;
	cout << "Matrix<int,2> m4: " << m4 << endl;
	Matrix<int,2> m5 = m1*m4;
	cout << "Matrix<int,2> m5 = m1*m4; m5: " << m5 << endl;
}

void matrix_numeration_all()
{
	cout << "@@ 29.3. matrix numeration @@\n";

	test_scalar_multiply();
	test_matrix_addition();
	test_matrix_product();
}

