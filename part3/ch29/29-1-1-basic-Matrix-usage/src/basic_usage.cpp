/*
 * basic_usage.cpp
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */


#include "Matrix.h"

#include <typeinfo>
#include <string>
using namespace std;

Matrix<double,0> md0{1};
Matrix<double,1> md1{1,2,3,4};
Matrix<double,2> md2{
	{00,01,02,03},
	{10,11,12,13},
	{20,21,22,23}
};

void initialize_from_matrix_initializer()
{
	cout << "-- initialize_from_matrix_initializer() --\n";

	cout << "md0{1}: " << md0 << endl;
	cout << "md1{1,2,3,4}: " << md1 << endl;
	cout << "md2{...}: " << md2 << endl;
}

Matrix<double,3> md3(4,7,9);
Matrix<double,17> md17;

void initialize_from_sizes()
{
	cout << "-- initialize_from_sizes() --\n";

	cout << "md3(4,7,9).desc: " << md3.descriptor() << endl;
	cout << "md17.desc: " << md17.descriptor() << endl;
}

Matrix<double,2> md;
Matrix<string,2> ms;

void various_element_type()
{
	cout << "-- various_element_type() --\n";
	cout << "typeid(md): " << typeid(md).name() << endl;
	cout << "typeid(ms): " << typeid(ms).name() << endl;
}

Matrix<Matrix<int,2>,2> mm {
	{
		{{1,2}, {3,4}},
		{{4,5}, {6,7}}
	},
	{
		{{8,9}, {0,1}},
		{{2,3}, {4,5}}
	},
	{
		{{1,2}, {3,4}},
		{{4,5}, {6,7}}
	}
};

void matrix_of_matrix()
{
	cout << "-- matrix_of_matrix() --\n";
	cout << "mm.desc: " << mm.descriptor() << endl;
	cout << "mm: " << mm << endl;
}

//Matrix<char,2> mc1(2,3,4);
	// error: static assertion failed: Matrix_slice<N>::Matrix_slice(Dims...): dimension mismatch
Matrix<char,2> mc2 {
	{'1', '2', '3'}
};
#if 0
Matrix<char,2> mc3 {
	{'1', '2', '3'},
	{'4', '5'}
};
#endif
	// Assertion `check_non_jagged<N>(list)' failed.

void check_dimension()
{
	cout << "-- check_dimension() --\n";

	cout << "mc2.desc: " << mc2.descriptor() << endl;
	cout << "mc2: " << mc2 << endl;
}

Matrix<double,1> m1(100);
Matrix<double,2> m2(50,6000);

auto d1 = m1.order;
auto d2 = m2.order;

auto e1 = m1.extent(0);
auto e2 = m1.extent(1);

auto e3 = m2.extent(0);
auto e4 = m2.extent(1);

auto s1 = m1.size();
auto s2 = m2.size();

void order_and_extent()
{
	cout << "-- order_and_extent() --\n";

	cout << "m1.desc: " << m1.descriptor() << endl;
	cout << "m2.desc: " << m2.descriptor() << endl;
	cout << "auto d1 = m1.order; " << d1 << endl;
	cout << "auto d2 = m2.order; " << d2 << endl;
	cout << "auto e1 = m1.extent(0); " << e1 << endl;
	cout << "(overflow) auto e2 = m1.extent(1); " << e2 << endl;
	cout << "auto e3 = m2.extent(0); " << e3 << endl;
	cout << "auto e4 = m2.extent(1); " << e4 << endl;
	cout << "auto s1 = m1.size(); " << s1 << endl;
	cout << "auto s2 = m2.size(); " << s2 << endl;
}

Matrix<double,2> m {
	{00,01,02,03},
	{10,11,12,13},
	{20,21,22,23}
};

double v1 = m(1,2);
double v2 = m[1][2];
Matrix<double,1> mr1 = m[1];
double v3 = mr1[2];

void index_access()
{
	cout << "-- index_access() --\n";

	cout << "m: " << m << endl;
	cout << "double v1 = m(1,2); " << v1 << endl;
	cout << "double v2 = m[1][2]; " << v2 << endl;
	cout << "Matrix<double,1> mr1 = m[1]; " << mr1 << endl;
	cout << "double v3 = mr1[2]; " << v3 << endl;
}

void basic_usage_all()
{
	cout << "@@ 29-1-1 basic_usage @@\n";

	initialize_from_matrix_initializer();
	initialize_from_sizes();
	various_element_type();
	matrix_of_matrix();
	check_dimension();
	order_and_extent();
	index_access();
}

