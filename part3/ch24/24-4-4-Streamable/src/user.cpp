/*
 * user.cpp
 *
 *  Created on: 2017/06/24
 *      Author: sasaki
 */

#include "streamable.h"
using namespace Estd;

#include <complex>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	bool b1 = Streamable<int>();
	bool b2 = Streamable<complex<double>>();
	bool b3 = Streamable<pair<int,double>>();
	bool b4 = Streamable<vector<int>>();

	cout << boolalpha;
	cout << "Streamable<int>(): " << b1 << endl;
	cout << "Streamable<complex<double>>(): " << b2 << endl;
	cout << "Streamable<pair<int,double>>(): " << b3 << endl;
	cout << "Streamable<vector<int>>(): " << b4 << endl;
}

