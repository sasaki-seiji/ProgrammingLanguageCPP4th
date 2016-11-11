/*
 * scalar_calculation.cpp
 *
 *  Created on: 2016/11/01
 *      Author: sasaki
 */

#include "Matrix.h"
#include <iostream>
#include <cmath>
using namespace std;

void test_apply_chain()
{
	cout << "--- test_apply_chain() --\n";

	Matrix<double,2> m {{1,-2,3}, {-4,5,-6}};
	cout << "m: " << m << endl;

	m.apply([](double& x){x=abs(x);}).apply([](double& x){x=sqrt(x);});
	cout << "m: " << m << endl;
}

