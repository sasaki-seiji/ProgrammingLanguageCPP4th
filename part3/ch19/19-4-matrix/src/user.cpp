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

	try {
		Vector v1 = {-2, -1, 0, 1, 2};
		cout << "successful construction v1: " << v1 << '\n';
	}
	catch (std::exception& e) {
		cout << e.what() << '\n';
	}

	try {
		Matrix m1 = {
				{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12}
		};
		cout << "successful contiruction m1: " << m1 << "\n";
	}
	catch (exception& e) {
		cout << e.what() << '\n';
	}

	try {
		Matrix m2 = {
				{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12},
				{13,14,15,16,17}
		};
		cout << "successful construction m2: " << m2 << '\n';
	}
	catch (exception& e) {
		cout << e.what() << '\n';
	}
}
