/*
 * user.cpp
 *
 *  Created on: 2016/07/30
 *      Author: sasaki
 */


#include "Matrix.h"
#include <iostream>
using namespace std;


int main()
{
	Matrix<int> m1{3,4};

	cout << "m1.size(): " << m1.size() << '\n';

	for (int i = 0; i < m1.rows() ; ++i) {
		for (int j = 0 ; j < m1.cols() ; ++j) {
			m1.at(i,j) = i+j;
		}
	}

	cout << "m1:\n";
	cout << m1;

	Matrix<int> m2 {m1};

	cout << "m2(copy of m1):\n";
	cout << m2;

	Matrix<int> m3{3,4};
	for (int i = 0; i < m3.rows() ; ++i) {
		for (int j = 0 ; j < m3.cols() ; ++j) {
			m3.at(i,j) = i-j;
		}
	}
	cout << "m3:\n";
	cout << m3;

	m3 = m1;
	cout << "m3(= m1):\n";
	cout << m3;

#if 0 // need move constructor/assign
	Matrix<int> m4{3,4};
	for (int i = 0; i < m4.rows() ; ++i) {
		for (int j = 0 ; j < m4.cols() ; ++j) {
			m4.at(i,j) = i*i+j;
		}
	}
	cout << "m4:\n";
	cout << m4;

	m4.assign(m1);
	cout << "m4(assign(m1)):\n";
	cout << m4;
#endif
}

