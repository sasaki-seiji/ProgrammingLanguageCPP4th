/*
 * user.cpp
 *
 *  Created on: 2016/07/30
 *      Author: sasaki
 */


#include "Matrix.h"
#include <iostream>
using namespace std;

struct X {
	int *p;
	X(int i=123) : p{new int{i}} { }
	~X() { delete p; }
	X(const X& x) : p{new int{*x.p}} { }
	X* operator=(const X& x) {
		*p = *x.p;
	}
};
ostream& operator<<(ostream& os, const X& x)
{
	return os << *x.p;
}


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

	Matrix<int> m4{3,4};
	for (int i = 0; i < m4.rows() ; ++i) {
		for (int j = 0 ; j < m4.cols() ; ++j) {
			m4.at(i,j) = i*i+j;
		}
	}
	cout << "m4:\n";
	cout << m4;

	m4.safe_assign(m1);
	cout << "m4(assign(m1)):\n";
	cout << m4;

	Matrix<X> mx1{3,4};
	for (int i = 0; i < mx1.rows() ; ++i) {
		for (int j = 0 ; j < mx1.cols() ; ++j) {
			mx1.at(i,j) = i+j;
		}
	}
	cout << "mx1:\n";
	cout << mx1;

	Matrix<X> mx2{mx1}; // copy
	cout << "mx2(copy of mx1):\n";
	cout << mx2;
}

