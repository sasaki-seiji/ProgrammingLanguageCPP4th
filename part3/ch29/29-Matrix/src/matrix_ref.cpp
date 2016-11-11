/*
 * matrix_ref.cpp
 *
 *  Created on: 2016/11/03
 *      Author: sasaki
 */


#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix_ref<double,1> user()
{
	Matrix<double,2> m = {{1,2}, {3,4}, {5,6}};
	cout << "m: " << m << endl;

	return m.row(1);
}

void test_missing_ref()
{
	cout << "--- test_missing_ref() --\n";

	auto mr = user();
	cout << "mr: " << mr << endl;
}
