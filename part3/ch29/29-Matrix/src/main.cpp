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
	test_nonnumeric_matrix();
	test_explicit_extents();

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

