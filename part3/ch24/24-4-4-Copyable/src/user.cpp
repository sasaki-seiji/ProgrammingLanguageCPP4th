/*
 * user.cpp
 *
 *  Created on: 2017/06/21
 *      Author: sasaki
 */


#include "copyable.h"
using namespace Estd;

#include <memory>
#include <vector>
#include <complex>
#include <iterator>
#include <iostream>
using namespace std;

int main()
{
	bool b1 = Copyable<int>();
	bool b2 = Copyable<vector<int>>();
	bool b3 = Copyable<complex<double>>();
	bool b4 = Copyable<ostream_iterator<char>>();
	bool b5 = Copyable<unique_ptr<int>>();
	bool b6 = Copyable<istream>();
	bool b7 = Copyable<type_info>();

	cout << boolalpha;
	cout << "Copyable<int>(): " << b1 << endl;
	cout << "Copyable<vector<int>>(): " << b2 << endl;
	cout << "Copyable<complex<double>>(): " << b3 << endl;
	cout << "Copyable<ostream_iterator<char>>(): " << b4 << endl;
	cout << "Copyable<unique_ptr<int>>(): " << b5 << endl;
	cout << "Copyable<istream>(): " << b6 << endl;
	cout << "Copyable<type_info>(): " << b7 << endl;
}
