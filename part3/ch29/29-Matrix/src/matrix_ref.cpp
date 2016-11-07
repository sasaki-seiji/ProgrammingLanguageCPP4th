/*
 * matrix_ref.cpp
 *
 *  Created on: 2016/11/03
 *      Author: sasaki
 */


#include "Matrix.h"

Matrix_ref<double,1> user()
{
	Matrix<double,2> m = {{1,2}, {3,4}, {5,6}};
	return m.row(1);
}

auto mr = user();

