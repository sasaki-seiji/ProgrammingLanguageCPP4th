/*
 * test_indexing_slicing.cpp
 *
 *  Created on: 2017/06/29
 *      Author: sasaki
 */

#include "Matrix_impl.h"

Matrix<int,2> m {
	{01,02,03},
	{11,12,13}
};

#if 0
m(1,2) = 99;
auto d1 = m(1);
auto d2 = m(1,2,3);
#endif

Matrix<int,2> m2 {
	{01,02,03},
	{11,12,13},
	{21,22,23}
};

//auto m22 = m2(slice{1,2},slice{0,3});

#if 0
m2(slice{1,2},slice{0,3}) = {
	{111,112,113},
	{121,122,123}
};
#endif

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
