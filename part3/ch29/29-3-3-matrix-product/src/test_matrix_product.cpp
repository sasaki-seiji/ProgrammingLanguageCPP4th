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

	Matrix<double,1> m1 {1, 2, 3, 4};
	Matrix<double,1> m2 {1.1, 2.2, 3.3};

	cout << "m1: " << m1 << endl;
	cout << "m2: " << m2 << endl;
	cout << "m1*m2: " << m1*m2 << endl;

}
