/*
 * test.h
 *
 *  Created on: 2016/11/06
 *      Author: sasaki
 */

#ifndef TEST_H_
#define TEST_H_

// test_basic_usage.cpp
void test_define_matrix();
void test_element_type();
void test_dimension();
void test_order_extent();
void test_index_access();
void test_stream_output();

// test_construct_and_assign.cpp
void test_Matrix_from_Matrix_initializer();
void test_Matrix_assign_Matrix_initializer();
void test_explicit_Matrix_from_extents();
void test_Matrix_from_Matrix_ref();
void test_Matrix_assign_Matrix_ref();
void test_Matrix_from_different_Matrix();
void test_Matrix_assign_different_Matrix();

// test_index_and_slicing.cpp
void test_Matrix_fortran_index();
void test_const_Matrix_fortran_index();
void test_Matrix_slice_index();
void test_const_Matrix_slice_index();
void test_Matrix_slice_and_int_index();
void test_const_Matrix_slice_and_int_index();
void test_Matrix_cstyle_index();
void test_const_Matrix_cstyle_index();
void test_Matrix_row2();
void test_const_Matrix_row2();
void test_Matrix_row1();
void test_const_Matrix_row1();
void test_Matrix_col2();
void test_const_Matrix_col2();
void test_Matrix_ref_fortran_index();
void test_const_Matrix_ref_fortran_index();
void test_Matrix_ref_slice_index();
void test_const_Matrix_ref_slice_index();
void test_Matrix_ref_slice_and_int_index();
void test_const_Matrix_ref_slice_and_int_index();
void test_Matrix_ref_cstyle_index();
void test_const_Matrix_ref_cstyle_index();
void test_Matrix_ref_row2();
void test_const_Matrix_ref_row2();
void test_Matrix_ref_row1();
void test_const_Matrix_ref_row1();
void test_Matrix_ref_col2();
void test_const_Matrix_ref_col2();

// test_arithmetic_calculation.cpp
void test_arithmetic_calculation();

// test_scalar_calculation.cpp
void test_apply_chain();
void test_Matrix_assign_scalar();
void test_Matrix_addassign_scalar();
void test_Matrix_subassign_scalar();
void test_Matrix_mulassign_scalar();
void test_Matrix_divassign_scalar();
void test_Matrix_modassign_scalar();
void test_Matrix_add_scalar();
void test_Matrix_sub_scalar();
void test_Matrix_mul_scalar();
void test_Matrix_div_scalar();
void test_Matrix_mod_scalar();
void test_Matrix_ref_assign_scalar();
void test_Matrix_ref_addassign_scalar();
void test_Matrix_ref_subassign_scalar();
void test_Matrix_ref_mulassign_scalar();
void test_Matrix_ref_divassign_scalar();
void test_Matrix_ref_modassign_scalar();
void test_Matrix_ref_add_scalar();
void test_Matrix_ref_sub_scalar();
void test_Matrix_ref_mul_scalar();
void test_Matrix_ref_div_scalar();
void test_Matrix_ref_mod_scalar();

// test_matrix_addition.cpp
void test_mixed_add();
void test_Matrix_addassign_Matrix();
void test_Matrix_addassign_Matrix_ref();
void test_Matrix_add_Matrix();

// test_matrix_ref.cpp
void test_missing_ref();

#endif /* TEST_H_ */
