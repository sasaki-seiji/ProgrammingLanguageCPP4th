/*
 * user.cpp
 *
 *  Created on: 2017/06/21
 *      Author: sasaki
 */

#include "movable.h"
using namespace Estd;

#include <vector>
#include <complex>
#include <iterator>
#include <memory>
#include <iostream>
using namespace std;

int main()
{
	bool b1 = Movable<int>();
	bool b2 = Movable<vector<int>>();
	bool b3 = Movable<complex<double>>();
	bool b4 = Movable<ostream_iterator<char>>();
	bool b5 = Movable<unique_ptr<int>>();
	bool b6 = Movable<istream>();
	bool b7 = Movable<type_info>();

	cout << boolalpha;
	cout << "Movable<int>(): " << b1 << endl;
	cout << "Movable<vector<int>>(): " << b2 << endl;
	cout << "Movable<complex<double>>(): " << b3 << endl;
	cout << "Movable<ostream_iterator<char>>(): " << b4 << endl;
	cout << "Movable<unique_ptr<int>>(): " << b5 << endl;
	cout << "Movable<istream>(): " << b6 << endl;
	cout << "Movable<type_info>(): " << b7 << endl;
}
