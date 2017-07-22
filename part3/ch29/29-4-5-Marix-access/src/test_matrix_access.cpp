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

	cout << "Matrix<int, 1> m1: " << m1 << endl;
	cout << "m1.row(2): " << m1_2 << endl;
	cout << "Matrix<int, 2> m2: " << m2 << endl;
	cout << "m2.row(1): " << m2_1 << endl;
	cout << "Matrix<int, 3> m3: " << m3 << endl;
	cout << "m3.row(1): " << m3_1 << endl;

	const Matrix<int, 1> cm1 {0,1,2,3};
	auto cm1_2 = cm1.row(2);
	const Matrix<int, 2> cm2 { {0,1,2,3}, {4,5,6,7} };
	auto cm2_1 = cm2.row(1);
	const Matrix<int, 3> cm3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };
	auto cm3_1 = cm3.row(1);

	cout << "const Matrix<int, 1> cm1: " << cm1 << endl;
	cout << "cm1.row(2): " << cm1_2 << endl;
	cout << "const Matrix<int, 2> cm2: " << cm2 << endl;
	cout << "cm2.row(1): " << cm2_1 << endl;
	cout << "const Matrix<int, 3> cm3: " << cm3 << endl;
	cout << "cm3.row(1): " << cm3_1 << endl;

}

void test_c_style_index()
{
	cout << "-- test_c_style_index() --\n";

	Matrix<int, 3> m3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };

	cout << "Matrix<int, 3> m3: " << m3 << endl;
	cout << "m3[1]: " << m3[1] << endl;
	cout << "m3[1][0]: " << m3[1][0] << endl;
	cout << "m3[1][0][2]: " << m3[1][0][2] << endl;

	const Matrix<int, 3> cm3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };

	cout << "const Matrix<int, 3> cm3: " << cm3 << endl;
	cout << "cm3[1]: " << cm3[1] << endl;
	cout << "cm3[1][0]: " << cm3[1][0] << endl;
	cout << "cm3[1][0][2]: " << cm3[1][0][2] << endl;
}

void test_col()
{
	cout << "-- test_col() --\n";

	Matrix<int, 3> m3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };
	cout << "Matrix<int, 3> m3: " << m3 << endl;
	cout << "m3.col(1): " << m3.col(1) << endl;
	cout << "m3.col(1).col(2): " << m3.col(1).col(2) << endl;

	const Matrix<int, 3> cm3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };
	cout << "const Matrix<int, 3> cm3: " << cm3 << endl;
	cout << "cm3.col(1): " << cm3.col(1) << endl;
	cout << "cm3.col(1).col(2): " << cm3.col(1).col(2) << endl;
}

void test_fortran_style_index()
{
	cout << "-- test_fortran_style_index() --\n";

	Matrix<int, 1> m1 {0,1,2,3};
	Matrix<int, 2> m2 { {0,1,2,3}, {4,5,6,7} };
	Matrix<int, 3> m3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };

	cout << "Matrix<int, 1> m1: " << m1 << endl;
	cout << "m1(2): " << m1(2) << endl;
	cout << "Matrix<int, 2> m2: " << m2 << endl;
	cout << "m2(1,2): " << m2(1,2) << endl;
	cout << "Matrix<int, 3> m3: " << m3 << endl;
	cout << "m3(1,1,1): " << m3(1,1,1) << endl;
	//cout << "m2(1): " << m2(1) << endl;
		// error: static assertion failed: Matrix<T,N>::operator()(size_t...): dimension mismatch
	//cout << "m2(1,2,0): " << m2(1,2,0) << endl;
		// error: static assertion failed: Matrix<T,N>::operator()(size_t...): dimension mismatch

	const Matrix<int, 1> cm1 {0,1,2,3};
	const Matrix<int, 2> cm2 { {0,1,2,3}, {4,5,6,7} };
	const Matrix<int, 3> cm3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };

	cout << "const Matrix<int, 1> cm1: " << cm1 << endl;
	cout << "cm1(2): " << cm1(2) << endl;
	cout << "const Matrix<int, 2> cm2: " << cm2 << endl;
	cout << "cm2(1,2): " << cm2(1,2) << endl;
	cout << "const Matrix<int, 3> cm3: " << cm3 << endl;
	cout << "cm3(1,1,1): " << cm3(1,1,1) << endl;
}

void test_slice_index()
{
	cout << "-- test_slice_index() --\n";

	Matrix<int, 1> m1 {0,1,2,3};
	Matrix<int, 2> m2 { {0,1,2,3}, {4,5,6,7}, {8,9,0,1} };
	Matrix<int, 3> m3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };

	cout << "Matrix<int, 1> m1: " << m1 << endl;
	cout << "m1(slice(2)): " << m1(slice(2)) << endl;
	cout << "Matrix<int, 2> m2: " << m2 << endl;
	cout << "m2(slice(1,2),slice(1,2,2)): " << m2(slice(1,2),slice(1,2,2)) << endl;
	cout << "m2(2,slice(0,3)): " << m2(2,slice(0,3)) << endl;
	cout << "m2(slice(1),2): " << m2(slice(1),2) << endl;
	cout << "Matrix<int, 3> m3: " << m3 << endl;
	cout << "m3(slice(1),1,slice(1)): " << m3(slice(1),1,slice(1)) << endl;

	const Matrix<int, 1> cm1 {0,1,2,3};
	const Matrix<int, 2> cm2 { {0,1,2,3}, {4,5,6,7}, {8,9,0,1} };
	const Matrix<int, 3> cm3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };

	cout << "const Matrix<int, 1> cm1: " << cm1 << endl;
	cout << "cm1(slice(2)): " << cm1(slice(2)) << endl;
	cout << "const Matrix<int, 2> cm2: " << cm2 << endl;
	cout << "cm2(slice(1,2),slice(1,2,2)): " << cm2(slice(1,2),slice(1,2,2)) << endl;
	cout << "cm2(2,slice(0,3)): " << cm2(2,slice(0,3)) << endl;
	cout << "cm2(slice(1),2): " << cm2(slice(1),2) << endl;
	cout << "const Matrix<int, 3> cm3: " << cm3 << endl;
	cout << "cm3(slice(1),1,slice(1)): " << cm3(slice(1),1,slice(1)) << endl;
}

void test_ref_row()
{
	cout << "-- test_ref_row() --\n";

	Matrix<int, 1> m1 {0,1,2,3};
	Matrix_ref<int,1> mr1 = m1(slice::all);
	auto mr1_2 = mr1.row(2);
	Matrix<int, 2> m2 { {0,1,2,3}, {4,5,6,7} };
	Matrix_ref<int,2> mr2 = m2(slice::all,slice::all);
	auto mr2_1 = mr2.row(1);
	Matrix<int, 3> m3 { { {0,1,2}, {3,4,5} }, { {6,7,8}, {9,0,1} } };
	Matrix_ref<int,3> mr3 = m3(slice::all,slice::all,slice::all);
	auto mr3_1 = mr3.row(1);

	cout << "Matrix_ref<int,1> mr1: " << mr1 << endl;
	cout << "mr1.row(2): " << mr1_2 << endl;
	cout << "Matrix_ref<int,2> mr2: " << mr2 << endl;
	cout << "mr2.row(1): " << mr2_1 << endl;
	cout << "Matrix_ref<int,3> mr3: " << mr3 << endl;
	cout << "mr3.row(1): " << mr3_1 << endl;
}


void test_matrix_access_all()
{
	cout << "@@ 29.4.5 Matrix access @@\n";

	test_row();
	test_c_style_index();
	test_col();
	test_fortran_style_index();
	test_slice_index();
	test_ref_row();

}

