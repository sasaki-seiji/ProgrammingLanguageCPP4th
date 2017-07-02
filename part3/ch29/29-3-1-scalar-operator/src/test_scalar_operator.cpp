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

	cout << "initially, m: " << m << endl;
	m += 1.2;
	cout << "after m += 1.2; m: " << m << endl;
	m -= 1.2;
	cout << "after m -= 1.2; m: " << m << endl;
	m *= 1.5;
	cout << "after m *= 1.5; m: " << m << endl;
	m /= 1.5;
	cout << "after m /= 1.5; m: " << m << endl;

	Matrix<int, 2> mi { {1,2,3}, {4,5,6}, {7,8,9} };

	cout << "initially, mi: " << mi << endl;
	mi %= 4;
	cout << "after mi %= 2; mi: " << mi << endl;

}

void succesive_apply()
{
	cout << "-- succesive_apply() --\n";

	Matrix<double, 2> m { {-1,2,-3}, {4,-5,6}, {-7,8,-9} };
	cout << "initially, m: " << m << endl;
	m.apply([](double& x){ x = abs(x); }).apply([](double& x){ x = sqrt(x); });
	cout << "after sqrt(abs(m)), m: " << m << endl;
}
