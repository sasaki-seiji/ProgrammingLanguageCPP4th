/*
 * main.cpp
 *
 *  Created on: 2017/07/08
 *      Author: sasaki
 */

#include "basic_usage.h"
#include "test_matrix_constructor.h"
#include "test_indexing_slicing.h"
#include "test_scalar_operator.h"
#include "test_matrix_addition.h"
#include "test_matrix_product.h"
#include "test_matrix_numeration.h"
#include "test_slice.h"
#include "test_matrix_slice.h"
#include "test_matrix_initializer.h"

int main()
{
	basic_usage_all();
	test_matrix_constructor_all();
	indexing_and_slicing_all();
	scalar_operator_all();
	matrix_addition_all();
	matrix_product_all();
	matrix_numeration_all();
	test_slice_all();
	test_matrix_slice_all();
	test_matrix_initializer_all();
}

