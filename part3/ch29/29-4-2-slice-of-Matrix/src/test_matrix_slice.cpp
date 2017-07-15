/*
 * test_matrix_slice.cpp
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#include "Matrix_slice.h"

#include <iostream>
using namespace std;

void test_matrix_slice_ctor()
{
	cout << "-- test_matrix_slice_ctor() --\n";

	Matrix_slice<3> ms1;
	Matrix_slice<3> ms2{3,{4,5,6}};
	Matrix_slice<3> ms3{3,{4,5,6},{120,24,2}};
	Matrix_slice<3> ms4{2,3,4};
	//Matrix_slice<3> ms5{2,3,4,5};
		// error: static assertion failed: Matrix_slice<N>::Matrix_slice(Dims...): dimension mismatch

	cout << "ms1: " << ms1 << endl;
	cout << "ms2{3,{4,5,6}}: " << ms2 << endl;
	cout << "ms3{3,{4,5,6},{120,24,2}}: " << ms3 << endl;
	cout << "ms4{2,3,4}: " << ms4 << endl;
}

void test_matrix_slice_index()
{
	cout << "-- test_matrix_slice_index() --\n";

	Matrix_slice<1> ms1{3,{4}};
	Matrix_slice<2> ms2{3,{4,5}};
	Matrix_slice<3> ms3{3,{4,5,6}};

	cout << "ms1{3,{4}}: " << ms1 << "-> ms1(1): " << ms1(1) << endl;
	cout << "ms2{3,{4,5}}: " << ms2 << "-> ms2(1,2): " << ms2(1,2) <<  endl;
	cout << "ms3{3,{4,5,6}}: " << ms3 << "-> ms3(1,2,3): " << ms3(1,2,3) << endl;
	//cout << "ms3(1,2,3,4): " << ms3(1,2,3,4) << endl;
		// static assertion failed: Matrix_slice<N>::operator(): dimension mismatch

}

void test_matrix_slice_all()
{
	cout << "@@ 29.4.2. slice of Matrix @@\n";

	test_matrix_slice_ctor();
	test_matrix_slice_index();
}

