/*
 * index_and_slicing.cpp
 *
 *  Created on: 2016/10/31
 *      Author: sasaki
 */

#include "Matrix.h"
#include <iostream>
using namespace std;

void test_Matrix_fortran_index()
{
	cout << "--- test_Matrix_fortran_index() --\n";

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

void test_const_Matrix_fortran_index()
{
	cout << "--- test_const_Matrix_fortran_index() --\n";

	const Matrix<int,2> m {
		{01,02,03},
		{11,12,13}
	};
	cout << "m: " << m << endl;

	cout << "m(1,2): " << m(1,2) << endl;

	//m(1,2) = 99;
		// error: assignment of read-only location 'm.Matrix<T, N>::operator()<{int, int}>(1, 2)'
}

void test_Matrix_slice_index()
{
	cout << "--- test_Matrix_slice_index() --\n";

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

void test_const_Matrix_slice_index()
{
	cout << "--- test_const_Matrix_slice_index() --\n";

	const Matrix<int,2> m2 {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m2: " << m2 << endl;

	auto m22 = m2(slice{1,2},slice{0,3});
	cout << "m22.desc: " << m22.descriptor() << endl;
	cout << "m22: " << m22 << endl;

#if 0
	m2(slice{1,2},slice{0,3}) = {
			{111,112,113},
			{121,122,123}
	};
		// error: assignment of read-only location '(& it)->Matrix_ref_iterator<T, N>::operator*<const int, 2ull>()' *it = v;
	cout << "m2: " << m2 << endl;
#endif
}

void test_Matrix_slice_and_int_index()
{
	cout << "--- test_Matrix_slice_and_int_index() --\n";

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

void test_const_Matrix_slice_and_int_index()
{
	cout << "--- test_const_Matrix_slice_and_int_index() --\n";

	const Matrix<int,2> m3 {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m3: " << m3 << endl;

	auto m31 = m3(slice{1,2},1);
	cout << "m31.desc: " << m31.descriptor() << endl;
	cout << "m31: " << m31 << endl;

	auto m32 = m3(slice{1,2},0);
	cout << "m32.desc: " << m32.descriptor() << endl;
	cout << "m32: " << m32 << endl;

	auto x = m3(1,2);
	cout << "x: " << x << endl;
}

void test_Matrix_cstyle_index()
{
	cout << "--- test_Matrix_cstyle_index() --\n";

	Matrix<int,2> m {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m: " << m << endl;

	auto r1 = m[1];
	cout << "r1.desc: " << r1.descriptor() << endl;
	cout << "r1: " << r1 << endl;

	r1 = {111,112,113};
	cout << "m: " << m << endl;
}

void test_const_Matrix_cstyle_index()
{
	cout << "--- test_const_Matrix_cstyle_index() --\n";

	const Matrix<int,2> m {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m: " << m << endl;

	auto r1 = m[1];
	cout << "r1.desc: " << r1.descriptor() << endl;
	cout << "r1: " << r1 << endl;

#if 0
	r1 = {111,112,113};
		// error: assignment of read-only location '(& it)->Matrix_ref_iterator<T, N>::operator*<const int, 1ull>()'
	cout << "m: " << m << endl;
#endif
}

void test_Matrix_row2()
{
	cout << "--- test_Matrix_row2() --\n";

	Matrix<int,2> m {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m: " << m << endl;

	auto r1 = m.row(1);
	cout << "r1.desc: " << r1.descriptor() << endl;
	cout << "r1: " << r1 << endl;

	r1 = {111,112,113};
	cout << "m: " << m << endl;
}

void test_const_Matrix_row2()
{
	cout << "--- test_const_Matrix_row2() --\n";

	const Matrix<int,2> m {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m: " << m << endl;

	auto r1 = m.row(1);
	cout << "r1.desc: " << r1.descriptor() << endl;
	cout << "r1: " << r1 << endl;

#if 0
	r1 = {111,112,113};
		// error: assignment of read-only location '(& it)->Matrix_ref_iterator<T, N>::operator*<const int, 1ull>()'  *it = v;
	cout << "m: " << m << endl;
#endif
}

void test_Matrix_row1()
{
	cout << "--- test_Matrix_row1() --\n";

	Matrix<int,1> m { 11,12,13 };
	cout << "m: " << m << endl;

	auto& r1 = m.row(1);
	cout << "r1: " << r1 << endl;

	r1 = 100;
	cout << "m: " << m << endl;
}

void test_const_Matrix_row1()
{
	cout << "--- test_const_Matrix_row1() --\n";

	const Matrix<int,1> m { 11,12,13 };
	cout << "m: " << m << endl;

	auto& r1 = m.row(1);
	cout << "r1: " << r1 << endl;

#if 0
	r1 = 100;
		// error: assignment of read-only reference 'r1'
	cout << "m: " << m << endl;
#endif
}

void test_Matrix_col2()
{
	cout << "--- test_Matrix_col2() --\n";

	Matrix<int,2> m {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m: " << m << endl;

	auto c1 = m.col(1);
	cout << "c1.desc: " << c1.descriptor() << endl;
	cout << "c1: " << c1 << endl;

	c1 = {101,102,103};
	cout << "m: " << m << endl;
}

void test_const_Matrix_col2()
{
	cout << "--- test_const_Matrix_col2() --\n";

	const Matrix<int,2> m {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m: " << m << endl;

	auto c1 = m.col(1);
	cout << "c1.desc: " << c1.descriptor() << endl;
	cout << "c1: " << c1 << endl;

#if 0
	c1 = {101,102,103};
		// error: assignment of read-only location '(& it)->Matrix_ref_iterator<T, N>::operator*<const int, 1ull>()'
	cout << "m: " << m << endl;
#endif
}

void test_Matrix_ref_fortran_index()
{
	cout << "--- test_Matrix_ref_fortran_index() --\n";

	Matrix<int,2> m {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m: " << m << endl;

	Matrix_ref<int,2> mr = m(slice(1,2),slice(0,3));
	cout << "mr: " << mr << endl;

	mr(1,2) = 99;
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
}

void test_const_Matrix_ref_fortran_index()
{
	cout << "--- test_const_Matrix_ref_fortran_index() --\n";

	const Matrix<int,2> m {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m: " << m << endl;

	Matrix_ref<const int,2> mr = m(slice(1,2),slice(0,3));
	cout << "mr: " << mr << endl;

#if 0
	mr(1,2) = 99;
		// error: assignment of read-only location 'mr.Matrix_ref<T, N>::operator()<{int, int}>(1, 2)'
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
#endif
}

void test_Matrix_ref_slice_index()
{
	cout << "--- test_Matrix_ref_slice_index() --\n";

	Matrix<int,2> m {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m: " << m << endl;

	Matrix_ref<int,2> mr = m(slice(1,2), slice(0,3));
	cout << "mr: " << mr << endl;

	auto mr01 = mr(slice(0,2),slice(1,2));
	cout << "mr01.desc: " << mr01.descriptor() << endl;
	cout << "mr01: " << mr01 << endl;

	mr(slice{0,2},slice{1,2}) = {
			{112,113},
			{122,123}
	};
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
}

void test_const_Matrix_ref_slice_index()
{
	cout << "--- test_const_Matrix_ref_slice_index() --\n";

	const Matrix<int,2> m {
		{01,02,03},
		{11,12,13},
		{21,22,23}
	};
	cout << "m: " << m << endl;

	Matrix_ref<const int,2> mr = m(slice(1,2), slice(0,3));
	cout << "mr: " << mr << endl;

	auto mr01 = mr(slice(0,2),slice(1,2));
	cout << "mr01.desc: " << mr01.descriptor() << endl;
	cout << "mr01: " << mr01 << endl;

#if 0
	mr(slice{0,2},slice{1,2}) = {
			{112,113},
			{122,123}
	};
		// error: assignment of read-only location '(& it)->Matrix_ref_iterator<T, N>::operator*<const int, 2ull>()'
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
#endif
}

