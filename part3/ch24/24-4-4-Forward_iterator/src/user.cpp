/*
 * user.cpp
 *
 *  Created on: 2017/06/18
 *      Author: sasaki
 */

#include "forward_iterator.h"
using namespace Estd;

#include <iterator>
#include <forward_list>
#include <list>
#include <vector>
#include <complex>
#include <iostream>
using namespace std;

void test_const_forward_iterator()
{
	cout << "-- test_const_forward_iterator() --\n";

	bool b1 = Const_forward_iterator<istream_iterator<char>>();
	bool b2 = Const_forward_iterator<ostream_iterator<char>>();
	bool b3 = Const_forward_iterator<forward_list<complex<double>>::const_iterator>();
	bool b4 = Const_forward_iterator<forward_list<complex<double>>::iterator>();
	bool b5 = Const_forward_iterator<list<int>::const_iterator>();
	bool b6 = Const_forward_iterator<list<int>::iterator>();
	bool b7 = Const_forward_iterator<vector<string>::const_iterator>();
	bool b8 = Const_forward_iterator<vector<string>::iterator>();
	bool b9 = Const_forward_iterator<const int*>();
	bool b10 = Const_forward_iterator<int*>();


	cout << boolalpha;
	cout << "Const_forward_iterator<istream_iterator<char>>(): " << b1 << endl;
	cout << "Const_forward_iterator<ostream_iterator<char>>(): " << b2 << endl;
	cout << "Const_forward_iterator<forward_list<complex<double>>::const_iterator>(): " << b3 << endl;
	cout << "Const_forward_iterator<forward_list<complex<double>>::iterator>(): " << b4 << endl;
	cout << "Const_forward_iterator<list<int>::const_iterator>(): " << b5 << endl;
	cout << "Const_forward_iterator<list<int>::iterator>(): " << b6 << endl;
	cout << "Const_forward_iterator<vector<string>::const_iterator>(): " << b7 << endl;
	cout << "Const_forward_iterator<vector<string>::iterator>(): " << b8 << endl;
	cout << "Const_forward_iterator<const int*>(): " << b9 << endl;
	cout << "Const_forward_iterator<int*>(): " << b10 << endl;

}

void test_forward_iterator()
{
	cout << "-- test_forward_iterator() --\n";

	bool b1 = Forward_iterator<istream_iterator<char>>();
	bool b2 = Forward_iterator<ostream_iterator<char>>();
	bool b3 = Forward_iterator<forward_list<complex<double>>::const_iterator>();
	bool b4 = Forward_iterator<forward_list<complex<double>>::iterator>();
	bool b5 = Forward_iterator<list<int>::const_iterator>();
	bool b6 = Forward_iterator<list<int>::iterator>();
	bool b7 = Forward_iterator<vector<string>::const_iterator>();
	bool b8 = Forward_iterator<vector<string>::iterator>();
	bool b9 = Forward_iterator<const int*>();
	bool b10 = Forward_iterator<int*>();


	cout << boolalpha;
	cout << "Forward_iterator<istream_iterator<char>>(): " << b1 << endl;
	cout << "Forward_iterator<ostream_iterator<char>>(): " << b2 << endl;
	cout << "Forward_iterator<forward_list<complex<double>>::const_iterator>(): " << b3 << endl;
	cout << "Forward_iterator<forward_list<complex<double>>::iterator>(): " << b4 << endl;
	cout << "Forward_iterator<list<int>::const_iterator>(): " << b5 << endl;
	cout << "Forward_iterator<list<int>::iterator>(): " << b6 << endl;
	cout << "Forward_iterator<vector<string>::const_iterator>(): " << b7 << endl;
	cout << "Forward_iterator<vector<string>::iterator>(): " << b8 << endl;
	cout << "Forward_iterator<const int*>(): " << b9 << endl;
	cout << "Forward_iterator<int*>(): " << b10 << endl;

}

int main()
{
	test_const_forward_iterator();
	test_forward_iterator();
}
