/*
 * main.cpp
 *
 *  Created on: 2016/11/06
 *      Author: sasaki
 */

#include "test.h"

int main()
{
	// basic_usage.cpp
	test_define_matrix();
	test_element_type();
	test_dimension();
	test_order_extent();
	test_index_access();
	test_stream_output();

	// construct_and_assign.cpp
	test_nonnumeric_matrix();
	test_explicit_extents();

}

