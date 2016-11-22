/*
 * test_matrix_multiplication.cpp
 *
 *  Created on: 2016/11/19
 *      Author: sasaki
 */


#include "Matrix.h"
#include "Matrix_multiply.h"
#include <iostream>
using namespace std;

void test_Matrix_1_mul_Matrix_1()
{
	cout << "--- test_Matrix_1_mul_Matrix_1() --\n";

	Matrix<double,1> m1 = { 1, 2, 3, 4 };
	Matrix<double,1> m2 = { 0.1, 0.2, 0.3, 0.4 };
	cout << "m1: " << m1 << endl;
	cout << "m2: " << m2 << endl;

	Matrix<double, 2> m3 = m1 * m2 ;
	cout << "m3: " << m3 << endl;
}


void test_Matrix_2_mul_Matrix_1()
{
	cout << "--- test_Matrix_2_mul_Matrix_1() --\n";

	Matrix<double,2> m1 = { {1, 2},{ 3, 4} };
	Matrix<double,1> m2 = { 0.1, 0.2 };
	cout << "m1: " << m1 << endl;
	cout << "m2: " << m2 << endl;

	Matrix<double, 1> m3 = m1 * m2 ;
	cout << "m3: " << m3 << endl;
}

void test_Matrix_2_mul_Matrix_2()
{
	cout << "--- test_Matrix_2_mul_Matrix_2() --\n";

	Matrix<double,2> m1 = { {1, 2},{ 3, 4} };
	Matrix<double,2> m2 = { { 0.1, 0.2 }, { 0.3, 0.4 } };
	cout << "m1: " << m1 << endl;
	cout << "m2: " << m2 << endl;

	Matrix<double,2> m3 = m1 * m2 ;
	cout << "m3: " << m3 << endl;
}


