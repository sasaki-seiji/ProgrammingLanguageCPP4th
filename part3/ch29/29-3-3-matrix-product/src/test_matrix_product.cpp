/*
 * test_matrix_product.cpp
 *
 *  Created on: 2017/07/06
 *      Author: sasaki
 */


#include "Matrix.h"

void test_marix1_x_matrix1()
{
	cout << "-- test_matrix1_x_matrix1() --\n";

	Matrix<double,1> v {1, 2, 3, 4};
	Matrix<double,1> u {1.1, 2.2, 3.3};

	cout << "v: " << v << endl;
	cout << "u: " << u << endl;
	cout << "v*u: " << v*u << endl;

}

void test_marix2_x_matrix1()
{
	cout << "-- test_matrix2_x_matrix1() --\n";

	Matrix<double,2> m { {1, 2, 3}, {4, 5, 6} };
	Matrix<double,1> v {1.1, 2.2, 3.3};

	cout << "m: " << m << endl;
	cout << "v: " << v << endl;
	cout << "m*v: " << m*v << endl;

}

void test_marix2_x_matrix2()
{
	cout << "-- test_matrix2_x_matrix2() --\n";

	Matrix<double,2> m1 { {1, 2, 3}, {4, 5, 6} };
	Matrix<double,2> m2 { {1,1}, {2,2}, {3,3}};

	cout << "m1: " << m1 << endl;
	cout << "m2: " << m2 << endl;
	cout << "m1*m2: " << m1*m2 << endl;

}
