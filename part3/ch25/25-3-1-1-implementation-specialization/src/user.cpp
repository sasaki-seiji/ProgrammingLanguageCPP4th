/*
 * user.cpp
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */

#include "Matrix.h"
#include <iostream>
using namespace std;

void test_Matrix0()
{
	cout << "-- test_Matrix0() --\n";

	Matrix<double, 0> m01{1.0}, m02{2.3};
	cout << "m01: " << m01 << endl;
	cout << "m02: " << m02 << endl;
	Matrix<double, 0> m03 = m01 + m02;
	cout << "m03(=m01+m02): " << m03 << endl;
}

void test_Matrix1()
{
	cout << "-- test_Matrix1() --\n";

	Matrix<double, 1> m11{1.1, 2.2, 3.3}, m12{4, 5, 6};
	cout << "m11: " << m11 << endl;
	cout << "m12: " << m12 << endl;
	Matrix<double, 1> m13 = m11 + m12;
	cout << "m13(=m11+m12): " << m13 << endl;
	Matrix<double, 1> m14{m13};
	cout << "m14{m13}: " << m14 << endl;
	swap(m11,m12);
	cout << "m11(swap): " << m11 << endl;
	cout << "m12(swap): " << m12 << endl;
}

void test_Matrix2()
{
	cout << "-- test_Matrix2() --\n";

	Matrix<double, 2> m21 = {
			{1, 2, 3},
			{4, 5, 6}
	};
	cout << "m21: " << m21 << endl;
	Matrix<double, 2> m22 = {
			{1.1, 1.2, 1.3},
			{2.1, 2.2, 2.3}
	};
	cout << "m22: " << m22 << endl;
	Matrix<double, 2> m23 = m21 + m22;
	cout << "m23(=m21+m22): " << m23 << endl;
	Matrix<double, 2> m24{m23};
	cout << "m24{m23}: " << m24 << endl;
	swap(m21,m22);
	cout << "m21(swap): " << m21 << endl;
	cout << "m22(swap): " << m22 << endl;
}

int main()
{
	test_Matrix0();
	test_Matrix1();
	test_Matrix2();
}
