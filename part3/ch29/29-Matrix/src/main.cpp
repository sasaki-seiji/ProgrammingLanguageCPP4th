/*
 * main.cpp
 *
 *  Created on: 2016/11/06
 *      Author: sasaki
 */

#include "test.h"
#include <iostream>
using namespace std;

int main()
{
	// test_basic_usage.cpp
	cout << "@@@ test_basic_usage.cpp @@@" << endl;
	test_define_matrix();
	test_element_type();
	test_dimension();
	test_order_extent();
	test_index_access();
	test_stream_output();

	// test_construct_and_assign.cpp
	cout << "\n@@@ test_construct_and_assign.cpp @@@" << endl;
	test_Matrix_from_Matrix_initializer();
	test_Matrix_assign_Matrix_initializer();
	test_explicit_Matrix_from_extents();
	test_Matrix_from_Matrix_ref();
	test_Matrix_assign_Matrix_ref();
	test_Matrix_from_different_Matrix();
	test_Matrix_assign_different_Matrix();


	// test_index_and_slicing.cpp
	cout << "\n@@@ test_index_and_slicing.cpp @@@" << endl;
	test_fortran_index();
	test_slice_index();
	test_slice_and_int_index();

	// test_arithmetic_calculation.cpp
	cout << "\n@@@ test_arithmetic_calculation.cpp @@@" << endl;
	test_arithmetic_calculation();

	// test_scalar_calculation.cpp
	cout << "\n@@@ test_scalar_calculation.cpp @@@" << endl;
	test_apply_chain();

	// test_matrix_addition.cpp
	cout << "\n@@@ test_matrix_addition.cpp @@@" << endl;
	test_mixed_add();

	// test_matrix_ref.cpp
	cout << "\n@@@ test_matrix_ref.cpp @@@" << endl;
	test_missing_ref();
}

