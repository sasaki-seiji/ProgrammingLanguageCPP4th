/*
 * user.cpp
 *
 *  Created on: 2016/07/31
 *      Author: sasaki
 */


#include "Matrix.h"
#include <iostream>
#include <vector>
using namespace std;

void f(string& s1, string& s2,
		vector<string>& vs1, vector<string>& vs2,
		Matrix<double>& m1, Matrix<double>& m2)
{
	swap(s1,s2);
	swap(vs1,vs2);
	swap(m1,m2);
}

ostream& operator<<(ostream&os, const vector<string>& vs)
{
	os << "[ ";
	for (auto& x : vs)
		os << x << ", ";
	os << "]";
	return os;
}

int main()
{
	Matrix<double> m1{3,4};

	cout << "m1.size(): " << m1.size() << '\n';

	for (int i = 0; i < m1.rows() ; ++i) {
		for (int j = 0 ; j < m1.cols() ; ++j) {
			m1.at(i,j) = i+j;
		}
	}

	cout << "m1:\n";
	cout << m1;

	Matrix<double> m2{3,4};
	for (int i = 0; i < m2.rows() ; ++i) {
		for (int j = 0 ; j < m2.cols() ; ++j) {
			m2.at(i,j) = i-j;
		}
	}
	cout << "m2:\n";
	cout << m2;

	Matrix<double> m3 = m1 + m2;	// move constructor
	cout << "Matrix m3 = m1+m2:\n";
	cout << m3;

	m1 = m2 + m3;	// move assignment
	cout << "m1 = m2 + m3:\n";
	cout << m1;

	string s1{"string#1"}, s2{"string#2"};
	vector<string> vs1 {"this", "is", "string", "vector", "No.1"};
	vector<string> vs2 {"that", "is", "string", "vector", "No.2"};
	cout << "- before f() call: -\n";
	cout << "s1 = " << s1 << ", s2 = " << s2 << endl;
	cout << "vs1 = " << vs1 << ", vs2 = " << vs2 << endl;
	f(s1,s2,vs1,vs2,m1,m2);
	cout << "- after f() call: -\n";
	cout << "s1 = " << s1 << ", s2 = " << s2 << endl;
	cout << "vs1 = " << vs1 << ", vs2 = " << vs2 << endl;
	cout << "m1:\n";
	cout << m1;
	cout << "m2:\n";
	cout << m2;
}
