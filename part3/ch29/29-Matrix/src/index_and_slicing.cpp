/*
 * index_and_slicing.cpp
 *
 *  Created on: 2016/10/31
 *      Author: sasaki
 */

#include "Matrix.h"

#if 0
Matrix<int,2> m {
	{01,02,03},
	{11,12,13}
};

m(1,2) = 99;
auto d1 = m(1);
auto d2 = m(1,2,3);

Matrix<int,2> m2 {
	{01,02,03},
	{11,12,13},
	{21,22,23}
};

auto m22 = m2(slice{1,2},slice{0,3});

m2(slice{1,2},slice{0,3}) = {
	{111,112,113},
	{121,122,123}
};

Matrix<int,2> m3 {
	{01,02,03},
	{11,12,13},
	{21,22,23}
};

auto m31 = m3(slice{1,2},1);
auto m32 = m3(slice{1,2},0);
auto x = m3(1,2);

#endif

