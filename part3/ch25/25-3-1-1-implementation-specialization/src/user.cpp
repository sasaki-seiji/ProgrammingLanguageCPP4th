/*
 * user.cpp
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */

#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
	Matrix<double, 0> m01{1.0}, m02{2.3};
	Matrix<double, 0> m03 = m01 + m02;
	cout << m03 << '\n';

	Matrix<double, 1> m11{1.2, 2.3, 3.4, 4.5}, m12{1, 2, 3, 4};
	Matrix<double, 1> m13 = m11 + m12;
	cout << m13 << '\n';

	Matrix<double, 2> m21 = {
			{1, 2, 3},
			{4, 5, 6}
	};
	Matrix<double, 2> m22 = {
			{1.1, 1.2, 1.3},
			{2.1, 2.2, 2.3}
	};
	Matrix<double, 2> m23 = m21 + m22;
	cout << m23 << '\n';
}
