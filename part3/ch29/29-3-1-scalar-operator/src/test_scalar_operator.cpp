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

void assign_scalar_to_ref()
{
	cout << "-- assign_scalar_to_ref() --\n";

	Matrix<double, 2> m { {1,2,3}, {4,5,6}, {7,8,9} };
	Matrix_ref<double, 2> mr = m(slice(1),slice(1));

	cout << "Matrix<double, 2> m { {1,2,3}, {4,5,6}, {7,8,9} };\n";
	cout << "m: "<< m << endl;
	cout << "Matrix<double, 2> mr = m(slice(1),slice(1));\n";
	cout << "mr: "<< mr << endl;
	mr += 1.2;
	cout << "mr += 1.2;\n";
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
	mr -= 1.2;
	cout << "mr -= 1.2;\n";
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
	mr *= 1.5;
	cout << "mr *= 1.5;\n";
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
	mr /= 1.5;
	cout << "mr /= 1.5;\n";
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;
	mr = 2.3;
	cout << "mr = 2.3;\n";
	cout << "mr: " << mr << endl;
	cout << "m: " << m << endl;

	Matrix<int, 2> mi { {1,2,3}, {4,5,6}, {7,8,9} };
	Matrix_ref<int, 2> mir = mi(slice(1),slice(1));

	cout << "Matrix<int, 2> mi { {1,2,3}, {4,5,6}, {7,8,9} };\n";
	cout << "Matrix_ref<int, 2> mir = mi(slice(1),slice(1));\n";

	cout << "mi: " << mi << endl;
	cout << "mir: " << mir << endl;
	mir %= 4;
	cout << "mir %= 4;\n";
	cout << "mir: " << mir << endl;
	cout << "mi: " << mi << endl;
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

void matrix_ref_scalar_operator()
{
	cout << "-- matrix_ref_scalar_operator() --\n";

	Matrix<int, 2> m { {1,2,3}, {4,5,6}, {7,8,9} };
	Matrix_ref<int, 2> mr = m(slice(1),slice(1));

	cout << "Matrix<int, 2> m { {1,2,3}, {4,5,6}, {7,8,9} };\n";
	cout << "Matrix_ref<int, 2> mr = m(slice(1),slice(1));\n";

	cout << "m: " << m << endl;
	cout << "mr: " << mr << endl;
	cout << "mr + 3: " << mr + 3 << endl;
	cout << "mr - 2: " << mr - 2 << endl;
	cout << "mr * 2: " << mr * 2 << endl;
	cout << "mr / 2: " << mr / 2 << endl;
	cout << "mr % 4: " << mr % 4 << endl;
}

void scalar_operator_all()
{
	cout << "@@ 29.3.1. scalar operator @@\n";

	assign_scalar();
	assign_scalar_to_ref();
	succesive_apply();
	matrix_scalar_operator();
	matrix_ref_scalar_operator();
}


