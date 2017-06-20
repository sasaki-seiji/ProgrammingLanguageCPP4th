/*
 * user.cpp
 *
 *  Created on: 2017/06/20
 *      Author: sasaki
 */

#include "totally_ordered.h"
using namespace Estd;

#include <vector>
#include <memory>
#include <complex>
#include <iostream>
using namespace std;

void test_single_type()
{
	cout << "-- test_single_type() --\n";

	bool b1 = Totally_ordered<int>();
	bool b2 = Totally_ordered<vector<int>>();
	bool b3 = Totally_ordered<unique_ptr<int>>();
	bool b4 = Totally_ordered<complex<double>>();
	bool b5 = Totally_ordered<istream>();

	cout << boolalpha;
	cout << "Totally_ordered<int>(): " << b1 << endl;
	cout << "Totally_ordered<vector<int>>(): " << b2 << endl;
	cout << "Totally_ordered<unique_ptr<int>>(): " << b3 << endl;
	cout << "Totally_ordered<complex<double>>(): " << b4 << endl;
	cout << "Totally_ordered<istream>(): " << b5 << endl;
}

void test_type_pair()
{
	cout << "-- test_type_pair() --\n";

	bool b1 = Totally_ordered<int,double>();
	bool b2 = Totally_ordered<double,complex<double>>();
	bool b3 = Equality_comparable<vector<int>,vector<double>>();

	cout << boolalpha;
	cout << "Totally_ordered<int,double>(): " << b1 << endl;
	cout << "Totally_ordered<double,complex<double>>(): " << b2 << endl;
	cout << "Totally_ordered<vector<int>,vector<double>>(): " << b3 << endl;
}

int main()
{
	test_single_type();
	test_type_pair();
}

