/*
 * test_matrix_access.cpp
 *
 *  Created on: 2017/06/30
 *      Author: sasaki
 */


#include "Matrix_impl.h"
#include "Matrix_ref_impl.h"

void test_row()
{
	cout << "-- test_row() --\n";

	Matrix<int, 1> m1 {0,1,2,3};
	auto m1_2 = m1.row(2);
	Matrix<int, 2> m2 { {0,1,2,3}, {4,5,6,7} };
	auto m2_1 = m2.row(1);
	Matrix<int, 3> m3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };
	auto m3_1 = m3.row(1);

	cout << "m1: " << m1 << endl;
	cout << "m1.row(2): " << m1_2 << endl;
	cout << "m2: " << m2 << endl;
	cout << "m2.row(1): " << m2_1 << endl;
	cout << "m3: " << m3 << endl;
	cout << "m3.row(1): " << m3_1 << endl;
}

void test_c_style_index()
{
	cout << "-- test_c_style_index() --\n";

	Matrix<int, 3> m3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };

	cout << "m3: " << m3 << endl;
	cout << "m3[1]: " << m3[1] << endl;
	cout << "m3[1][0]: " << m3[1][0] << endl;
	cout << "m3[1][0][2]: " << m3[1][0][2] << endl;
}

void test_col()
{
	cout << "-- test_col() --\n";

	Matrix<int, 3> m3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };
	cout << "m3: " << m3 << endl;
	cout << "m3.col(1): " << m3.col(1) << endl;
	cout << "m3.col(1).col(2): " << m3.col(1).col(2) << endl;

	const Matrix<int, 3> cm3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };
	cout << "cm3: " << cm3 << endl;
	cout << "cm3.col(1): " << cm3.col(1) << endl;
	cout << "cm3.col(1).col(2): " << cm3.col(1).col(2) << endl;
}
