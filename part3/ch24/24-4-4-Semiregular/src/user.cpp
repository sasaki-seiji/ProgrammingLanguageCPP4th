/*
 * user.cpp
 *
 *  Created on: 2017/06/22
 *      Author: sasaki
 */

#include "semiregular.h"
using namespace Estd;

#include <vector>
#include <complex>
#include <memory>
#include <iterator>
#include <iostream>
using namespace std;

int main()
{
	bool b1 = Semiregular<int>();
	bool b2 = Semiregular<vector<int>>();
	bool b3 = Semiregular<complex<double>>();
	bool b4 = Semiregular<ostream_iterator<char>>();
	bool b5 = Semiregular<unique_ptr<int>>();
	bool b6 = Semiregular<istream>();
	bool b7 = Semiregular<type_info>();

	cout << boolalpha;
	cout << "Semiregular<int>(): " << b1 << endl;
	cout << "Semiregular<vector<int>>(): " << b2 << endl;
	cout << "Semiregular<complex<double>>(): " << b3 << endl;
	cout << "Semiregular<ostream_iterator<char>>(): " << b4 << endl;
	cout << "Semiregular<unique_ptr<int>>(): " << b5 << endl;
	cout << "Semiregular<istream>(): " << b6 << endl;
	cout << "Semiregular<type_info>(): " << b7 << endl;
}

