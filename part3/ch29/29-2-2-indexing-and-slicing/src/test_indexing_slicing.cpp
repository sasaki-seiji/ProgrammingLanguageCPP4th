/*
 * test_indexing_slicing.cpp
 *
 *  Created on: 2017/06/29
 *      Author: sasaki
 */

#include "Matrix_impl.h"
#include "Matrix_ref_impl.h"

void access_by_int_index()
{
	cout << "-- access_by_int_index() --\n";

	Matrix<int,2> m {
		{01,02,03},
		{11,12,13}
	};
	cout << "Matrix<int,2> m: " << m << endl;
	m(1,2) = 99;
	//auto d1 = m(1);
		// error: static assertion failed: Matrix<T,N>::operator()(size_t...): dimension mismatch
	//auto d2 = m(1,2,3);
		// error: static assertion failed: Matrix<T,N>::operator()(size_t...): dimension mismatch
	cout << "m(1,2) = 99; m: " << m << endl;

	const Matrix<int,2> mc {
		{01,02,03},
		{11,12,13}
	};
	cout << "const Matrix<int,2> mc: " << mc << endl;
	cout << "mc(1,2): " << mc(1,2) << endl;

	Matrix<int,0> m0 {10};
	cout << "Matrix<int,0> m0: " << m0 << endl;
	m0() = 101;
	cout << "m() = 101; m0: " << m0 << endl;

	const Matrix<int,0> mc0 {10};
	cout << "const Matrix<int,0> mc0: " << mc0 << endl;
	cout << "mc0(): " << mc0() << endl;
}

void access_by_slice_index()
{
	cout << "-- access_by_slice_index() --\n";

	Matrix<int,2> m2 {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};

	auto m22 = m2(slice{1,2},slice{0,3});

	cout << "Matrix<int,2> m2: " << m2 << endl;
	cout << "auto m22 = m2(slice{1,2},slice{0,3}); " << m22 << endl;

	const Matrix<int,2> mc2 {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};

	auto mc22 = mc2(slice{1,2},slice{0,3});

	cout << "const Matrix<int,2> mc2: " << mc2 << endl;
	cout << "auto mc22 = mc2(slice{1,2},slice{0,3}); " << mc22 << endl;
}

void assign_to_sliced_matrix()
{
	cout << "-- assign_to_sliced_matrix() --\n";

	Matrix<int,2> m2 {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};

	m2(slice{1,2},slice{0,3}) = {
			{111,112,113},
			{121,122,123}
	};

	cout << "m2: " << m2 << endl;
	cout << "m2(slice{1,2},slice(0,3}) = {{111,112,113},{121,122,123}};\n";
	cout << "m2: " << m2 << endl;
}

void access_by_slice_and_int_index()
{
	cout << "-- access_by_slice_and_int_index() --\n";

	Matrix<int,2> m3 {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};

	auto m31 = m3(slice{1,2},1);
	auto m32 = m3(slice{1,2},0);
	auto x = m3(1,2);

	cout << "m3: " << m3 << endl;
	cout << "auto m31 = m3(slice{1,2},1); m31: " << m31 << endl;
	cout << "auto m32 = m3(slice{1,2},0); m32: " << m32 << endl;
	cout << "auto x = m3(1,2); x: " << x << endl;
}

void indexing_and_slicing_all()
{
	cout << "@@ 29.2.2 indexing_and_slicing @@\n";

	access_by_int_index();
	access_by_slice_index();
	assign_to_sliced_matrix();
	access_by_slice_and_int_index();

}
