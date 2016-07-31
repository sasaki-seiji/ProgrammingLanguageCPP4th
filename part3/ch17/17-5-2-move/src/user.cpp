/*
 * user.cpp
 *
 *  Created on: 2016/07/31
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

	Matrix<int> m2{3,4};
	for (int i = 0; i < m2.rows() ; ++i) {
		for (int j = 0 ; j < m2.cols() ; ++j) {
			m2.at(i,j) = i-j;
		}
	}
	cout << "m2:\n";
	cout << m2;

	Matrix<int> m3 = m1 + m2;	// move constructor
	cout << "Matrix m3 = m1+m2:\n";
	cout << m3;

	m1 = m2 + m3;	// move assignment
	cout << "m1 = m2 + m3:\n";
	cout << m1;

}



