/*
 * user.cpp
 *
 *  Created on: 2016/08/18
 *      Author: sasaki
 */

#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
	Vector v = {-1, 0, 1, 2};
	Matrix m = {
			{ 0, 1, 2, 3},
			{ -3, -2, -1, 0},
			{ -2, -1, 0, 1},
			{ 3, 2, 1, 0}
	};

	cout << "v: " << v << '\n';

	Vector r = m * v;
	cout << "r: " << r << '\n';
}
