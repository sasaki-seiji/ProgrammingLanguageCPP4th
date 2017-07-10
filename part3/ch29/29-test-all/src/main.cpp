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

int main()
{
	basic_usage_all();
	test_matrix_constructor_all();
	indexing_and_slicing_all();
	scalar_operator_all();
}

