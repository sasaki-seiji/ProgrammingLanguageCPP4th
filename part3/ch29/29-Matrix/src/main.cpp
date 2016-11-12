/*
 * main.cpp
 *
 *  Created on: 2016/11/06
 *      Author: sasaki
 */

#include "test.h"

int main()
{
	// test_basic_usage.cpp
	test_define_matrix();
	test_element_type();
	test_dimension();
	test_order_extent();
	test_index_access();
	test_stream_output();

	// test_construct_and_assign.cpp
	test_Matrix_from_Matrix_initializer();
	test_Matrix_assign_Matrix_initializer();
	test_explicit_Matrix_from_extents();
	test_Matrix_from_Matrix_ref();
	test_Matrix_assign_Matrix_ref();
	test_Matrix_from_different_Matrix();
	test_Matrix_assign_different_Matrix();


	// test_index_and_slicing.cpp
	test_fortran_index();
	test_slice_index();
	test_slice_and_int_index();

	// test_arithmetic_calculation.cpp
	test_arithmetic_calculation();

	// test_scalar_calculation.cpp
	test_apply_chain();

	// test_matrix_addition.cpp
	test_mixed_add();

	// test_matrix_ref.cpp
	test_missing_ref();
}

