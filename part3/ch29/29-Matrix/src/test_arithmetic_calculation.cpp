/*
 * arithmetic_calculation.cpp
 *
 *  Created on: 2016/11/01
 *      Author: sasaki
 */

#include "Matrix.h"
#include <iostream>
using namespace std;

void test_arithmetic_calculation()
{
	cout << "--- test_arithmetic_calculation() --\n";

	Matrix<int,2> mi {{1,2,3}, {4,5,6}};
	cout << "mi: " << mi << endl;

	Matrix<int,2> m2 {mi};
	cout << "m2: " << m2 << endl;

	mi*=2;
	cout << "mi: " << mi << endl;

	Matrix<int,2> m3 = mi+m2;
	cout << "m3: " << m3 << endl;

	Matrix<int,2> m4 {{1,2}, {3,4}, {5,6}};
	Matrix<int,2> m5 = mi*m4;
	cout << "m4: " << m4 << endl;
	cout << "m5: " << m5 << endl;
}

