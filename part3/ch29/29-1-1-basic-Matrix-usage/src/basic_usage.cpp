/*
 * basic_usage.cpp
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */


#include "Matrix.h"

#include <string>
using namespace std;

Matrix<double,0> md0{1};
Matrix<double,1> md1{1,2,3,4};
Matrix<double,2> md2{
	{00,01,02,03},
	{10,11,12,13},
	{20,21,22,23}
};

Matrix<double,3> md3(4,7,9);
Matrix<double,17> md17;

Matrix<double,2> md;
Matrix<string,2> ms;

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


Matrix<char,2> mc1(2,3,4);
Matrix<char,2> mc2 {
	{'1', '2', '3'}
};
Matrix<char,2> mc2 {
	{'1', '2', '3'},
	{'4', '5'}
};

Matrix<double,1> m1(100);
Matrix<double,2> m2(50,6000);

auto d1 = m1.order();
auto d2 = m2.order();

auto e1 = m1.extent(0);
auto e2 = m1.extent(1);

auto e3 = m2.extent(0);
auto e4 = m2.extent(1);

auto s1 = m1.size();
auto s2 = m2.size();

Matrix<double,2> m {
	{00,01,02,03},
	{10,11,12,13},
	{20,21,22,23}
};

double v1 = m(1,2);
double v2 = m[1][2];
Matrix<double,1> mr1 = m[1];
double v3 = mr1[2];

