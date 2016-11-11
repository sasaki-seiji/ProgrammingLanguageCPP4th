/*
 * test.h
 *
 *  Created on: 2016/11/06
 *      Author: sasaki
 */

#ifndef TEST_H_
#define TEST_H_

// basic_usage.cpp
void test_define_matrix();
void test_element_type();
void test_dimension();
void test_order_extent();
void test_index_access();
void test_stream_output();

// construct_and_assign.cpp
void test_nonnumeric_matrix();
void test_explicit_extents();

// index_and_slicing.cpp
void test_fortran_index();
void test_slice_index();
void test_slice_and_int_index();

// arithmetic_calculation.cpp
void test_arithmetic_calculation();

// scalar_calculation.cpp
void test_apply_chain();

// matrix_addition.cpp
void test_mixed_add();

// matrix_ref.cpp
void test_missing_ref();

#endif /* TEST_H_ */
