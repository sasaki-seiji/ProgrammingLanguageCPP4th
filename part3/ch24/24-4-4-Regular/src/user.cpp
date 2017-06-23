/*
 * user.cpp
 *
 *  Created on: 2017/06/22
 *      Author: sasaki
 */

#include "regular.h"
using namespace Estd;

#include <vector>
#include <complex>
#include <iterator>
#include <memory>
#include <iostream>
using namespace std;

int main()
{
	bool b1 = Regular<int>();
	bool b2 = Regular<vector<int>>();
	bool b3 = Regular<complex<double>>();
	bool b4 = Regular<ostream_iterator<char>>();
	bool b5 = Regular<unique_ptr<int>>();
	bool b6 = Regular<istream>();
	bool b7 = Regular<type_info>();

	cout << boolalpha;
	cout << "Regular<int>(): " << b1 << endl;
	cout << "Regular<vector<int>>(): " << b2 << endl;
	cout << "Regular<complex<double>>(): " << b3 << endl;
	cout << "Regular<ostream_iterator<char>>(): " << b4 << endl;
	cout << "Regular<unique_ptr<int>>(): " << b5 << endl;
	cout << "Regular<istream>(): " << b6 << endl;
	cout << "Regular<type_info>(): " << b7 << endl;
}



