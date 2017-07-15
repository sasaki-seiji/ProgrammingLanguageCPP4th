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

	cout << "Matrix<double,1> v: " << v << endl;
	cout << "Matrix<double,1> u: " << u << endl;
	cout << "v*u: " << v*u << endl;

}

void test_marix1_x_matrix1_ref()
{
	cout << "-- test_matrix1_x_matrix1_ref() --\n";

	Matrix<double,1> v {1, 2, 3, 4};
	Matrix<double,1> u {1.1, 2.2, 3.3, 4.4};
	Matrix_ref<double,1> ur = u(slice(1));

	cout << "Matrix<double,1> v: " << v << endl;
	cout << "Matrix_ref<double,1> ur: " << ur << endl;
	cout << "v*ur: " << v*ur << endl;

}

void test_marix1_ref_x_matrix1()
{
	cout << "-- test_matrix1_ref_x_matrix1() --\n";

	Matrix<double,1> v {1, 2, 3, 4, 5};
	Matrix_ref<double,1> vr = v(slice(1));
	Matrix<double,1> u {1.1, 2.2, 3.3};

	cout << "Matrix_ref<double,1> vr: " << vr << endl;
	cout << "Matrix<double,1> u: " << u << endl;
	cout << "vr*u: " << vr*u << endl;

}

void test_marix1_ref_x_matrix1_ref()
{
	cout << "-- test_matrix1_ref_x_matrix1_ref() --\n";

	Matrix<double,1> v {1, 2, 3, 4, 5};
	Matrix_ref<double,1> vr = v(slice(1));
	Matrix<double,1> u {1.1, 2.2, 3.3, 4.4};
	Matrix_ref<double,1> ur = u(slice(1));

	cout << "Matrix_ref<double,1> vr: " << vr << endl;
	cout << "Matrix_ref<double,1> ur: " << ur << endl;
	cout << "vr*ur: " << vr*ur << endl;

}

void test_marix2_x_matrix1()
{
	cout << "-- test_matrix2_x_matrix1() --\n";

	Matrix<double,2> m { {1, 2, 3}, {4, 5, 6} };
	Matrix<double,1> v {1.1, 2.2, 3.3};

	cout << "Matrix<double,2> m: " << m << endl;
	cout << "Matrix<double,1> v: " << v << endl;
	cout << "m*v: " << m*v << endl;

}

void test_marix2_x_matrix1_ref()
{
	cout << "-- test_matrix2_x_matrix1_ref() --\n";

	Matrix<double,2> m { {1, 2}, {3, 4} };
	Matrix<double,1> v {1.1, 2.2, 3.3};
	Matrix_ref<double,1> vr = v(slice(1));

	cout << "Matrix<double,2> m: " << m << endl;
	cout << "Matrix_ref<double,1> vr: " << vr << endl;
	cout << "m*vr: " << m*vr << endl;

}

void test_marix2_ref_x_matrix1()
{
	cout << "-- test_matrix2_ref_x_matrix1() --\n";

	Matrix<double,2> m { {1, 2, 3}, {4, 5, 6} };
	Matrix_ref<double,2> mr = m(slice(0),slice(1));
	Matrix<double,1> v {1.1, 2.2};

	cout << "Matrix_ref<double,2> mr: " << mr << endl;
	cout << "Matrix<double,1> v: " << v << endl;
	cout << "mr*v: " << mr*v << endl;

}

void test_marix2_ref_x_matrix1_ref()
{
	cout << "-- test_matrix2_ref_x_matrix1_ref() --\n";

	Matrix<double,2> m { {1, 2, 3}, {4, 5, 6} };
	Matrix_ref<double,2> mr = m(slice(0),slice(1));
	Matrix<double,1> v {1.1, 2.2, 3.3};
	Matrix_ref<double,1> vr = v(slice(1));

	cout << "Matrix_ref<double,2> mr: " << mr << endl;
	cout << "Matrix_ref<double,1> vr: " << vr << endl;
	cout << "mr*vr: " << mr*vr << endl;

}

void test_marix2_x_matrix2()
{
	cout << "-- test_matrix2_x_matrix2() --\n";

	Matrix<double,2> m1 { {1, 2, 3}, {4, 5, 6} };
	Matrix<double,2> m2 { {1,1}, {2,2}, {3,3}};

	cout << "Matrix<double,2> m1: " << m1 << endl;
	cout << "Matrix<double,2> m2: " << m2 << endl;
	cout << "m1*m2: " << m1*m2 << endl;

}

void matrix_product_all()
{
	cout << "@@ 29.3.3. matrix product @@\n";

	test_marix1_x_matrix1();
	test_marix1_x_matrix1_ref();
	test_marix1_ref_x_matrix1();
	test_marix1_ref_x_matrix1_ref();
	test_marix2_x_matrix1();
	test_marix2_x_matrix1_ref();
	test_marix2_ref_x_matrix1();
	test_marix2_ref_x_matrix1_ref();
	test_marix2_x_matrix2();
}

