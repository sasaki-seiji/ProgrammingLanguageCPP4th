/*
 * user.cpp
 *
 *  Created on: 2017/06/18
 *      Author: sasaki
 */


#include "random_access_iterator.h"
using namespace Estd;

#include <iterator>
#include <forward_list>
#include <list>
#include <vector>
#include <complex>
#include <iostream>
using namespace std;

void test_const_random_access_iterator()
{
	cout << "-- test_const_random_access_iterator() --\n";

	bool b1 = Const_random_access_iterator<istream_iterator<char>>();
	bool b2 = Const_random_access_iterator<ostream_iterator<char>>();
	bool b3 = Const_random_access_iterator<forward_list<complex<double>>::const_iterator>();
	bool b4 = Const_random_access_iterator<forward_list<complex<double>>::iterator>();
	bool b5 = Const_random_access_iterator<list<int>::const_iterator>();
	bool b6 = Const_random_access_iterator<list<int>::iterator>();
	bool b7 = Const_random_access_iterator<vector<string>::const_iterator>();
	bool b8 = Const_random_access_iterator<vector<string>::iterator>();
	bool b9 = Const_random_access_iterator<const int*>();
	bool b10 = Const_random_access_iterator<int*>();


	cout << boolalpha;
	cout << "Const_random_access_iterator<istream_iterator<char>>(): " << b1 << endl;
	cout << "Const_random_access_iterator<ostream_iterator<char>>(): " << b2 << endl;
	cout << "Const_random_access_iterator<forward_list<complex<double>>::const_iterator>(): " << b3 << endl;
	cout << "Const_random_access_iterator<forward_list<complex<double>>::iterator>(): " << b4 << endl;
	cout << "Const_random_access_iterator<list<int>::const_iterator>(): " << b5 << endl;
	cout << "Const_random_access_iterator<list<int>::iterator>(): " << b6 << endl;
	cout << "Const_random_access_iterator<vector<string>::const_iterator>(): " << b7 << endl;
	cout << "Const_random_access_iterator<vector<string>::iterator>(): " << b8 << endl;
	cout << "Const_random_access_iterator<const int*>(): " << b9 << endl;
	cout << "Const_random_access_iterator<int*>(): " << b10 << endl;

}

void test_random_access_iterator()
{
	cout << "-- test_random_access_iterator() --\n";

	bool b1 = Random_access_iterator<istream_iterator<char>>();
	bool b2 = Random_access_iterator<ostream_iterator<char>>();
	bool b3 = Random_access_iterator<forward_list<complex<double>>::const_iterator>();
	bool b4 = Random_access_iterator<forward_list<complex<double>>::iterator>();
	bool b5 = Random_access_iterator<list<int>::const_iterator>();
	bool b6 = Random_access_iterator<list<int>::iterator>();
	bool b7 = Random_access_iterator<vector<string>::const_iterator>();
	bool b8 = Random_access_iterator<vector<string>::iterator>();
	bool b9 = Random_access_iterator<const int*>();
	bool b10 = Random_access_iterator<int*>();


	cout << boolalpha;
	cout << "Random_access_iterator<istream_iterator<char>>(): " << b1 << endl;
	cout << "Random_access_iterator<ostream_iterator<char>>(): " << b2 << endl;
	cout << "Random_access_iterator<forward_list<complex<double>>::const_iterator>(): " << b3 << endl;
	cout << "Random_access_iterator<forward_list<complex<double>>::iterator>(): " << b4 << endl;
	cout << "Random_access_iterator<list<int>::const_iterator>(): " << b5 << endl;
	cout << "Random_access_iterator<list<int>::iterator>(): " << b6 << endl;
	cout << "Random_access_iterator<vector<string>::const_iterator>(): " << b7 << endl;
	cout << "Random_access_iterator<vector<string>::iterator>(): " << b8 << endl;
	cout << "Random_access_iterator<const int*>(): " << b9 << endl;
	cout << "Random_access_iterator<int*>(): " << b10 << endl;

}


int main()
{
	test_const_random_access_iterator();
	test_random_access_iterator();
}



