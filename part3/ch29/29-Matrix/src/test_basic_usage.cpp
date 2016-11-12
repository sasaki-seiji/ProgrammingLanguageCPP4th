/*
 * basic_usage.cpp
 *
 *  Created on: 2016/10/30
 *      Author: sasaki
 */

#include "Matrix.h"

#include <complex>
#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;


void test_define_matrix()
{
	cout << "--- test_define_matrix() --\n";

	Matrix<double,0> m0{1};
	Matrix<double,1> m1{1,2,3,4};
	Matrix<double,2> m2{
		{00,01,02,03},
		{10,11,12,13},
		{20,21,22,23}
	};

	Matrix<double,3> m3(4,7,9);
	Matrix<complex<double>,17> m17;

	cout << "m0 - " << m0() << endl;
	cout << "m1 - " << m1.descriptor() << endl;
	cout << "m2 - " << m2.descriptor() << endl;
	cout << "m3 - " << m3.descriptor() << endl;
	cout << "m17 - " << m17.descriptor() << endl;
}

void test_element_type()
{
	cout << "--- test_element_type() --\n";

	Matrix<double,2> md;
	Matrix<string,2> ms;

	Matrix<Matrix<int,2>,2> mm {
		{
			{{1, 2}, {3, 4}},
			{{4, 5}, {6, 7}}
		},
		{
			{{8, 9}, {0, 1}},
			{{2, 3}, {4, 5}}
		},
		{
			{{1, 2}, {3, 4}},
			{{4, 5}, {6, 7}}
		}
	};

	cout << "md(0,0): " << typeid(md(0,0)).name() << endl;
	cout << "ms(0,0): " << typeid(ms(0,0)).name() << endl;
	cout << "mm(0,0): " << typeid(mm(0,0)).name() << endl;
}

void test_dimension()
{
	cout << "--- test_dimension() --\n";

	//Matrix<char,2> mc1(2,3,4);
		// error: no matching function for call to 'Matrix_slice<2ull>::Matrix_slice(int&, int&, int&)'
	Matrix<char,2> mc2 {
		{'1', '2', '3'}
	};
#if 0 // assert
	Matrix<char,2> mc3 {
		{'1','2','3'},
		{'4','5'}
	};
#endif

}

void test_order_extent()
{
	cout << "--- test_order_extent() --\n";

	Matrix<double,1> m1(100);
	Matrix<double,2> m2(50,6000);

#if 0 // 2016.11.06 change
	auto d1 = m1.order();
	auto d2 = m2.order();
#else
	auto d1 = m1.order;
	auto d2 = m2.order;
#endif

	auto e1 = m1.extent(0);
	auto e2 = m1.extent(1);
	auto e3 = m2.extent(0);
	auto e4 = m2.extent(1);

	auto s1 = m1.size();
	auto s2 = m2.size();

	cout << "d1: " << d1 << endl;
	cout << "d2: " << d2 << endl;
	cout << "e1: " << e1 << endl;
	cout << "e2: " << e2 << endl;
	cout << "e3: " << e3 << endl;
	cout << "e4: " << e4 << endl;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
}

void test_index_access()
{
	cout << "--- test_index_access() --\n";

	Matrix<double,2> m {
		{00,01,02,03},
		{10,11,12,13},
		{20,21,22,23}
	};

	double d1 = m(1,2);
	double d2 = m[1][2];
	Matrix<double,1> m1 = m[1];
	double d3 = m1[2];

	cout << "m.desc: " << m.descriptor() << endl;
	cout << "d1: " << d1 << endl;
	cout << "m[1].desc: " << m[1].descriptor() << endl;
	cout << "d2: " << d2 << endl;
	cout << "d3: " << d3 << endl;
}

#if 0 // 2016.11.10 move to Matrix_util.h
template<typename M>
	Enable_if<Matrix_type<M>(),ostream&>
operator<<(ostream& os, const M& m)
{
	os << '{';
	for (size_t i = 0; i!=m.rows(); ++i) {
		os << m[i];
		if (i+1!=m.rows()) os << ',';
	}
	return os << '}';
}
#endif

void test_stream_output()
{
	cout << "--- test_stream_output() --\n";

	Matrix<double,2> m {
		{00,01,02,03},
		{10,11,12,13},
		{20,21,22,23}
	};

	cout << m << '\n';
}

