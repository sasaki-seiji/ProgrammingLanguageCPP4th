/*
 * test_scalar_operator.cpp
 *
 *  Created on: 2017/07/02
 *      Author: sasaki
 */

#include "Matrix.h"


void assign_scalar()
{
	cout << "-- assign_scalar() --\n";

	Matrix<double, 2> m { {1,2,3}, {4,5,6}, {7,8,9} };

	cout << "Matrix<double, 2> m { {1,2,3}, {4,5,6}, {7,8,9} };\n";
	cout << "m: "<< m << endl;
	m += 1.2;
	cout << "m += 1.2; m: " << m << endl;
	m -= 1.2;
	cout << "m -= 1.2; m: " << m << endl;
	m *= 1.5;
	cout << "m *= 1.5; m: " << m << endl;
	m /= 1.5;
	cout << "m /= 1.5; m: " << m << endl;
	m = 2.3;
	cout << "m = 2.3; m: " << m << endl;

	Matrix<int, 2> mi { {1,2,3}, {4,5,6}, {7,8,9} };

	cout << "Matrix<int, 2> mi { {1,2,3}, {4,5,6}, {7,8,9} };\n";
	cout << "mi: " << mi << endl;
	mi %= 4;
	cout << "mi %= 4; mi: " << mi << endl;

}

void succesive_apply()
{
	cout << "-- succesive_apply() --\n";

	Matrix<double, 2> m { {-1,2,-3}, {4,-5,6}, {-7,8,-9} };

	cout << "Matrix<double, 2> m { {-1,2,-3}, {4,-5,6}, {-7,8,-9} };\n";
	cout << "m: " << m << endl;
	m.apply([](double& x){ x = abs(x); }).apply([](double& x){ x = sqrt(x); });
	cout << "sqrt(abs(m)), m: " << m << endl;
}

void matrix_scalar_operator()
{
	cout << "-- matrix_scalar_operator() --\n";

	Matrix<int, 2> m { {1,2,3}, {4,5,6}, {7,8,9} };

	cout << "Matrix<int, 2> m { {1,2,3}, {4,5,6}, {7,8,9} };\n";
	cout << "m: " << m << endl;
	cout << "m + 3: " << m + 3 << endl;
	cout << "m - 2: " << m - 2 << endl;
	cout << "m * 2: " << m * 2 << endl;
	cout << "m / 2: " << m / 2 << endl;
	cout << "m % 4: " << m % 4 << endl;
}

void scalar_operator_all()
{
	cout << "@@ 29.3.1. scalar operator @@\n";

	assign_scalar();
	succesive_apply();
	matrix_scalar_operator();
}


