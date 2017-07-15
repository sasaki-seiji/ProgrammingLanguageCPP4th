/*
 * test_matrix_initializer.cpp
 *
 *  Created on: 2017/06/26
 *      Author: sasaki
 */


#include "Matrix_concept.h"
#include "Matrix_slice.h"
#include "Matrix_impl_impl.h"

#include <vector>
#include <iostream>
using namespace std;

Matrix_initializer<int,1> mi1 {1, 2, 3};

Matrix_initializer<int,2> mi2 {
	{1, 2, 3},
	{4, 5, 6}
};

Matrix_initializer<int,3> mi3 {
	{ {1, 2, 3}, {4, 5, 6} },
	{ {7, 8, 9}, {11, 12, 13} }
};

void test_matrix_initializer()
{
	cout << "-- test_matrix_initializer() --\n";

	cout << "mi1: " << mi1 << endl;
	cout << "mi2: " << mi2 << endl;
	cout << "mi3: " << mi3 << endl;
}

void test_derive_extents()
{
	cout << "-- test_derive_extents() --\n";

	Matrix_initializer<int,1> mi1 {1,2,3};
	auto exts1 = Matrix_impl::derive_extents<1>(mi1);
	Matrix_initializer<int,2> mi2 { {1,2,3}, {4,5,6} };
	auto exts2 = Matrix_impl::derive_extents<2>(mi2);
	Matrix_initializer<int,3> mi3 { { {1,2,3}, {4,5,6} }, { {7,8,9}, {0,1,2} } };
	auto exts3 = Matrix_impl::derive_extents<3>(mi3);

	cout << "mi1: " << mi1 << " -> exts1: " << exts1 << endl;
	cout << "mi2: " << mi2 << " -> exts2: " << exts2 << endl;
	cout << "mi3: " << mi3 << " -> exts3: " << exts3 << endl;
}

void test_compute_strides()
{
	cout << "-- test_compute_strides() --\n";

	Matrix_initializer<int,1> mi1 {1,2,3};
	Matrix_slice<1> ms1;
	ms1.extents = Matrix_impl::derive_extents<1>(mi1);
	Matrix_impl::compute_strides(ms1);

	Matrix_initializer<int,2> mi2 { {1,2,3}, {4,5,6} };
	Matrix_slice<2> ms2;
	ms2.extents = Matrix_impl::derive_extents<2>(mi2);
	Matrix_impl::compute_strides(ms2);

	Matrix_initializer<int,3> mi3 { { {1,2,3}, {4,5,6} }, { {7,8,9}, {0,1,2} } };
	Matrix_slice<3> ms3;
	ms3.extents = Matrix_impl::derive_extents<3>(mi3);
	Matrix_impl::compute_strides(ms3);

	cout << "mi1: " << mi1 << " -> ms1: " << ms1 << endl;
	cout << "mi2: " << mi2 << " -> ms2: " << ms2 << endl;
	cout << "mi3: " << mi3 << " -> ms3: " << ms3 << endl;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << "[ ";
	for ( auto x : v)
		os << x << ' ';
	return os << "]";
}

void test_insert_flat()
{
	cout << "-- test_insert_flat() --\n";

	Matrix_initializer<int,1> mi1 {1,2,3};
	vector<int> v1;
	Matrix_impl::insert_flat(mi1, v1);

	Matrix_initializer<int,2> mi2 { {1,2,3}, {4,5,6} };
	vector<int> v2;
	Matrix_impl::insert_flat(mi2, v2);

	Matrix_initializer<int,3> mi3 { { {1,2,3}, {4,5,6} }, { {7,8,9}, {0,1,2} } };
	vector<int> v3;
	Matrix_impl::insert_flat(mi3, v3);

	cout << "mi1: " << mi1 << " -> v1: " << v1 << endl;
	cout << "mi2: " << mi2 << " -> v2: " << v2 << endl;
	cout << "mi3: " << mi3 << " -> v3: " << v3 << endl;
}

void test_matrix_initializer_all()
{
	cout << "@@ 29.4.4. initialize Matrix from initializer_list @@\n";

	test_matrix_initializer();
	test_derive_extents();
	test_compute_strides();
	test_insert_flat();
}


