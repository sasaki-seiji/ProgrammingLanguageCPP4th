/*
 * test_matrix_numeration.cpp
 *
 *  Created on: 2017/07/02
 *      Author: sasaki
 */


#include "Matrix.h"

Matrix<int,2> m1 {{1,2,3},{4,5,6}};
Matrix<int,2> m2 {m1};
m1 *= 2;
Matrix<int,2> m3 = m1+m3;
Matrix<int,2> m4 {{1,2},{3,4},{5,6}};
Matrix<int,2> m5 = m1*m4;


