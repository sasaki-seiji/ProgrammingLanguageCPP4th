/*
 * test_matrix_initializer.cpp
 *
 *  Created on: 2016/11/20
 *      Author: sasaki
 */


#include "Matrix.h"
#include <iostream>
#include <array>
using namespace std;

template<typename T, size_t N>
ostream& operator<<(ostream& os, array<T,N>& a)
{
	for (auto& elem : a)
		os << elem << ' ';
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
	for (auto& elem : v)
		os << elem << ' ';
	return os;
}

void test_Matrix_initializer_1()
{
	cout << "--- test_Matrix_initializer_1() --\n";

	Matrix_initializer<int,1> mi { 1, 2, 3 };

	array<size_t,1> extents = Matrix_impl::derive_extents<1>(mi);
	cout << "extents: " << extents << endl;

	vector<int> vec;
	Matrix_impl::insert_flat(mi, vec);
	cout << "vec: " << vec << endl;

	Matrix_initializer<int,1> mi2 { 11, 22, 33 };
	auto it = vec.begin();
	Matrix_impl::copy_flat(mi2, it);
	cout << "vec: " << vec << endl;
}

void test_Matrix_initializer_2()
{
	cout << "--- test_Matrix_initializer_2() --\n";

	Matrix_initializer<int,2> mi { {1, 2}, {3, 4}, {5, 6} };

	array<size_t,2> extents = Matrix_impl::derive_extents<2>(mi);
	cout << "extents: " << extents << endl;

	vector<int> vec;
	Matrix_impl::insert_flat(mi, vec);
	cout << "vec: " << vec << endl;

	Matrix_initializer<int,2> mi2 { {11, 22}, {33, 44}, {55, 66} };
	auto it = vec.begin();
	Matrix_impl::copy_flat(mi2, it);
	cout << "vec: " << vec << endl;
}

void test_Matrix_initializer_3()
{
	cout << "--- test_Matrix_initializer_3() --\n";

	Matrix_initializer<int,3> mi {
		{{1, 2}, {3, 4}},
		{{5, 6}, {7, 8}},
		{{9, 10}, {11, 12}}
	};

	array<size_t,3> extents = Matrix_impl::derive_extents<3>(mi);
	cout << "extents: " << extents << endl;

	vector<int> vec;
	Matrix_impl::insert_flat(mi, vec);
	cout << "vec: " << vec << endl;

	Matrix_initializer<int,3> mi2 {
		{{11, 22}, {33, 44}},
		{{55, 66}, {77, 88}},
		{{99, 1010}, {1111, 1212}}
	};
	auto it = vec.begin();
	Matrix_impl::copy_flat(mi2, it);
	cout << "vec: " << vec << endl;
}

void test_jagged_Matrix_initializer()
{
	cout << "--- test_jagged_Matrix_initializer() --\n";

	Matrix_initializer<int, 3> mi {
		{{1,2}, {3,4}, {5,6}},
		{{7,8}, {9,10}, {11,12,13}}
	};

#if 0 // asserted
	array<size_t,3> extents = Matrix_impl::derive_extents<3>(mi);
	cout << "extents: " << extents << endl;
#endif
}
