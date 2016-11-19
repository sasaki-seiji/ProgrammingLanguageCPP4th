/*
 * test_matrix_slice.cpp
 *
 *  Created on: 2016/11/19
 *      Author: sasaki
 */


#include "Matrix.h"
#include <iostream>
using namespace std;

void test_default_Matrix_slice()
{
	cout << "--- test_default_Matrix_slice() --\n";

	Matrix_slice<3> ms3;
	cout << "default Matrix_slice<3>: " << ms3 << endl;

	Matrix_slice<2> ms2;
	cout << "default Matrix_slice<2>: " << ms2 << endl;

	Matrix_slice<1> ms1;
	cout << "default Matrix_slice<1>: " << ms1 << endl;
}

void test_Matrix_slice_from_offset_extents()
{
	cout << "--- test_Matrix_slice_from_offset_extents() --\n";

	Matrix_slice<3> ms3(10, {2, 3, 4});
	cout << "ms3: " << ms3 << endl;

	cout << "ms3(0,0,0): " << ms3(0,0,0) << endl;
	cout << "ms3(1,2,3): " << ms3(1,2,3) << endl;

	Matrix_slice<2> ms2(10, {2, 3});
	cout << "ms2: " << ms2 << endl;

	cout << "ms2(0,0): " << ms2(0,0) << endl;
	cout << "ms2(1,2): " << ms2(1,2) << endl;

	Matrix_slice<1> ms1(10, {2});
	cout << "ms1: " << ms1 << endl;

	cout << "ms1(0): " << ms1(0) << endl;
	cout << "ms1(1): " << ms1(1) << endl;

}

void test_Matrix_slice_from_offset_extents_strides()
{
	cout << "--- test_Matrix_slice_from_offset_extents_strides() --\n";

	Matrix_slice<3> ms3(10, {2, 3, 4}, {24, 8, 2});
	cout << "ms3: " << ms3 << endl;

	cout << "ms3(0,0,0): " << ms3(0,0,0) << endl;
	cout << "ms3(1,2,3): " << ms3(1,2,3) << endl;

	Matrix_slice<2> ms2(10, {3, 4}, {8, 2});
	cout << "ms2: " << ms2 << endl;

	cout << "ms2(0,0): " << ms2(0,0) << endl;
	cout << "ms2(2,3): " << ms2(2,3) << endl;

	Matrix_slice<1> ms1(10, {4}, {2});
	cout << "ms1: " << ms1 << endl;

	cout << "ms1(0): " << ms1(0) << endl;
	cout << "ms1(3): " << ms1(3) << endl;

}

void test_Matrix_slice_from_variadic_extent()
{
	cout << "--- test_Matrix_slice_from_variadic_extent() --\n";

	Matrix_slice<3> ms3(2, 3, 4);
	cout << "ms3: " << ms3 << endl;
	cout << "ms3(0,0,0): " << ms3(0,0,0) << endl;
	cout << "ms3(1,2,3): " << ms3(1,2,3) << endl;

	Matrix_slice<2> ms2(3, 4);
	cout << "ms2: " << ms2 << endl;
	cout << "ms2(0,0): " << ms2(0,0) << endl;
	cout << "ms2(2,3): " << ms2(2,3) << endl;

	Matrix_slice<1> ms1(4);
	cout << "ms1: " << ms1 << endl;
	cout << "ms1(0): " << ms1(0) << endl;
	cout << "ms1(3): " << ms1(3) << endl;
}
