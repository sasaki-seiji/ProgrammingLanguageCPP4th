/*
 * stack_process.cpp
 *
 *  Created on: 2016/11/25
 *      Author: sasaki
 */

#include <vector>
#include <complex>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto x : v)
		os << x << ' ';
	return os;
}

int main()
{
	vector<complex<double>> vc;
	for (double re, im; cin>>re>>im; )
		vc.emplace_back(re,im);

	cout << "vc: " << vc << endl;
}

