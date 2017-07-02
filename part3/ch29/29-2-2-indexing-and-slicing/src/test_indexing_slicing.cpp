/*
 * test_indexing_slicing.cpp
 *
 *  Created on: 2017/06/29
 *      Author: sasaki
 */

#include "Matrix_impl.h"
#include "Matrix_ref_impl.h"

Matrix<int,2> m {
	{01,02,03},
	{11,12,13}
};

void access_by_int_index()
{
	cout << "-- access_by_int_index() --\n";

	cout << "m: " << m << endl;

	m(1,2) = 99;
	//auto d1 = m(1);
		// error: static assertion failed: Matrix<T,N>::operator()(size_t...): dimension mismatch
	//auto d2 = m(1,2,3);
		// error: static assertion failed: Matrix<T,N>::operator()(size_t...): dimension mismatch

	cout << "after m(1,2) = 99; m: " << m << endl;
}

Matrix<int,2> m2 {
	{01,02,03},
	{11,12,13},
	{21,22,23}
};

auto m22 = m2(slice{1,2},slice{0,3});

void access_by_slice_index()
{
	cout << "-- access_by_slice_index() --\n";

	cout << "m2: " << m2 << endl;
	cout << "auto m22 = m2(slice{1,2},slice{0,3}); " << m22 << endl;
}

void assign_to_sliced_matrix()
{
	cout << "-- assig_to_sliced_matrix() --\n";

	m2(slice{1,2},slice{0,3}) = {
			{111,112,113},
			{121,122,123}
	};

	cout << "after assign to m2(slice{1,2},slice(0,3}), m2: " << m2 << endl;
}

Matrix<int,2> m3 {
	{01,02,03},
	{11,12,13},
	{21,22,23}
};

#if 0
auto m31 = m3(slice{1,2},1);
auto m32 = m3(slice{1,2},0);
auto x = m3(1,2);
#endif
