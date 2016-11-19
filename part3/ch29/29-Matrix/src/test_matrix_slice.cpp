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

	Matrix_slice<3> ms;
	cout << "default Matrix_slice<3>: " << ms << endl;

}

void test_Matrix_slice_from_offset_extents()
{
	cout << "--- test_Matrix_slice_from_offset_extents() --\n";

	Matrix_slice<3> ms(10, {2, 3, 4});
	cout << "ms: " << ms << endl;

	cout << "ms(0,0,0): " << ms(0,0,0) << endl;
	cout << "ms(1,2,3): " << ms(1,2,3) << endl;
}

void test_Matrix_slice_from_offset_extents_strides()
{
	cout << "--- test_Matrix_slice_from_offset_extents_strides() --\n";

	Matrix_slice<3> ms(10, {2, 3, 4}, {20, 5, 1});
	cout << "ms: " << ms << endl;

	cout << "ms(0,0,0): " << ms(0,0,0) << endl;
	cout << "ms(1,2,3): " << ms(1,2,3) << endl;
}
