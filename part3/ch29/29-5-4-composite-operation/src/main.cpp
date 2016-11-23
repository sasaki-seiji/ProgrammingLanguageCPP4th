/*
 * main.cpp
 *
 *  Created on: 2016/11/23
 *      Author: sasaki
 */


#include "composite_operation.h"
#include <iostream>
using namespace std;

int main()
{
	Vec V = { 1, 2, 3 };
	Vec W = { -3, -2, -1 };
	Mat2d M = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

	cout << "V: " << V << endl;
	cout << "W: " << W << endl;
	cout << "M: " << M << endl;

	Vec U = M*V+W;
	cout << "U: " << U << endl;

	Vec U2(3);
	U2 = M*V+W;
	cout << "U2: " << U2 << endl;
}

