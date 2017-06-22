/*
 * user.cpp
 *
 *  Created on: 2017/06/22
 *      Author: sasaki
 */


#include "ordered.h"
using namespace Estd;

#include <vector>
#include <complex>
#include <iterator>
#include <memory>
#include <iostream>
using namespace std;

int main()
{
	bool b1 = Ordered<int>();
	bool b2 = Ordered<vector<int>>();
	bool b3 = Ordered<complex<double>>();
	bool b4 = Ordered<ostream_iterator<char>>();
	bool b5 = Ordered<unique_ptr<int>>();
	bool b6 = Ordered<istream>();
	bool b7 = Ordered<type_info>();

	cout << boolalpha;
	cout << "Ordered<int>(): " << b1 << endl;
	cout << "Ordered<vector<int>>(): " << b2 << endl;
	cout << "Ordered<complex<double>>(): " << b3 << endl;
	cout << "Ordered<ostream_iterator<char>>(): " << b4 << endl;
	cout << "Ordered<unique_ptr<int>>(): " << b5 << endl;
	cout << "Ordered<istream>(): " << b6 << endl;
	cout << "Ordered<type_info>(): " << b7 << endl;
}




