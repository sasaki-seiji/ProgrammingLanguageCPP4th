/*
 * user.cpp
 *
 *  Created on: 2017/06/18
 *      Author: sasaki
 */


#include "bidirectional_iterator.h"
using namespace Estd;

#include <iterator>
#include <forward_list>
#include <list>
#include <vector>
#include <complex>
#include <iostream>
using namespace std;

void test_const_bidirectional_iterator()
{
	cout << "-- test_const_bidirectional_iterator() --\n";

	bool b1 = Const_bidirectional_iterator<istream_iterator<char>>();
	bool b2 = Const_bidirectional_iterator<ostream_iterator<char>>();
	bool b3 = Const_bidirectional_iterator<forward_list<complex<double>>::const_iterator>();
	bool b4 = Const_bidirectional_iterator<forward_list<complex<double>>::iterator>();
	bool b5 = Const_bidirectional_iterator<list<int>::const_iterator>();
	bool b6 = Const_bidirectional_iterator<list<int>::iterator>();
	bool b7 = Const_bidirectional_iterator<vector<string>::const_iterator>();
	bool b8 = Const_bidirectional_iterator<vector<string>::iterator>();
	bool b9 = Const_bidirectional_iterator<const int*>();
	bool b10 = Const_bidirectional_iterator<int*>();


	cout << boolalpha;
	cout << "Const_bidirectional_iterator<istream_iterator<char>>(): " << b1 << endl;
	cout << "Const_bidirectional_iterator<ostream_iterator<char>>(): " << b2 << endl;
	cout << "Const_bidirectional_iterator<forward_list<complex<double>>::const_iterator>(): " << b3 << endl;
	cout << "Const_bidirectional_iterator<forward_list<complex<double>>::iterator>(): " << b4 << endl;
	cout << "Const_bidirectional_iterator<list<int>::const_iterator>(): " << b5 << endl;
	cout << "Const_bidirectional_iterator<list<int>::iterator>(): " << b6 << endl;
	cout << "Const_bidirectional_iterator<vector<string>::const_iterator>(): " << b7 << endl;
	cout << "Const_bidirectional_iterator<vector<string>::iterator>(): " << b8 << endl;
	cout << "Const_bidirectional_iterator<const int*>(): " << b9 << endl;
	cout << "Const_bidirectional_iterator<int*>(): " << b10 << endl;

}

void test_bidirectional_iterator()
{
	cout << "-- test_bidirectional_iterator() --\n";

	bool b1 = Bidirectional_iterator<istream_iterator<char>>();
	bool b2 = Bidirectional_iterator<ostream_iterator<char>>();
	bool b3 = Bidirectional_iterator<forward_list<complex<double>>::const_iterator>();
	bool b4 = Bidirectional_iterator<forward_list<complex<double>>::iterator>();
	bool b5 = Bidirectional_iterator<list<int>::const_iterator>();
	bool b6 = Bidirectional_iterator<list<int>::iterator>();
	bool b7 = Bidirectional_iterator<vector<string>::const_iterator>();
	bool b8 = Bidirectional_iterator<vector<string>::iterator>();
	bool b9 = Bidirectional_iterator<const int*>();
	bool b10 = Bidirectional_iterator<int*>();


	cout << boolalpha;
	cout << "Bidirectional_iterator<istream_iterator<char>>(): " << b1 << endl;
	cout << "Bidirectional_iterator<ostream_iterator<char>>(): " << b2 << endl;
	cout << "Bidirectional_iterator<forward_list<complex<double>>::const_iterator>(): " << b3 << endl;
	cout << "Bidirectional_iterator<forward_list<complex<double>>::iterator>(): " << b4 << endl;
	cout << "Bidirectional_iterator<list<int>::const_iterator>(): " << b5 << endl;
	cout << "Bidirectional_iterator<list<int>::iterator>(): " << b6 << endl;
	cout << "Bidirectional_iterator<vector<string>::const_iterator>(): " << b7 << endl;
	cout << "Bidirectional_iterator<vector<string>::iterator>(): " << b8 << endl;
	cout << "Bidirectional_iterator<const int*>(): " << b9 << endl;
	cout << "Bidirectional_iterator<int*>(): " << b10 << endl;

}


int main()
{
	test_const_bidirectional_iterator();
	test_bidirectional_iterator();
}

