/*
 * reference_to_reference.cpp
 *
 *  Created on: 2016/04/17
 *      Author: sasaki
 */

using rr_i = int&&;
using lr_i = int&;
using rr_rr_i = rr_i&&;
using lr_rr_i = rr_i&;
using rr_lr_i = lr_i&&;
using lr_lr_i = lr_i&;

int i;
//int && & r = i;
	// cannot declare reference to 'int&&', which is not a typedef or a template type argument
