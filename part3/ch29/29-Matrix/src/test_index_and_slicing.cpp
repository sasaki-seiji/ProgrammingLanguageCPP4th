/*
 * index_and_slicing.cpp
 *
 *  Created on: 2016/10/31
 *      Author: sasaki
 */

#include "Matrix.h"
#include <iostream>
using namespace std;

void test_fortran_index()
{
	cout << "--- test_fortran_index() --\n";

	Matrix<int,2> m {
		{01,02,03},
		{11,12,13}
	};

	m(1,2) = 99;
	//auto d1 = m(1);
		// error: no match for call to '(Matrix_slice<2ull>) (int&)'
	//auto d2 = m(1,2,3);
		// error: no match for call to '(Matrix_slice<2ull>) (int&, int&, int&)'

	cout << "m: " << m << endl;
}

void test_slice_index()
{
	cout << "--- test_slice_index() --\n";

	Matrix<int,2> m2 {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m2: " << m2 << endl;

	auto m22 = m2(slice{1,2},slice{0,3});
	cout << "m22.desc: " << m22.descriptor() << endl;
	cout << "m22: " << m22 << endl;

	m2(slice{1,2},slice{0,3}) = {
			{111,112,113},
			{121,122,123}
	};
	cout << "m2: " << m2 << endl;
}

void test_slice_and_int_index()
{
	cout << "--- test_slice_and_int_index() --\n";

	Matrix<int,2> m3 {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m3: " << m3 << endl;

	auto m31 = m3(slice{1,2},1);
	auto m32 = m3(slice{1,2},0);
	auto x = m3(1,2);

	cout << "m31: " << m31 << endl;
	cout << "m32: " << m32 << endl;
	cout << "x: " << x << endl;
}
