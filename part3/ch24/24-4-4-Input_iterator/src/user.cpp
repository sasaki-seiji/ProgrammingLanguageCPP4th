/*
 * user.cpp
 *
 *  Created on: 2017/06/16
 *      Author: sasaki
 */

#include "iterator.h"
using namespace Estd;

#include <typeinfo>
#include <iterator>
#include <forward_list>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	bool b1 = Input_iterator<istream_iterator<char>>();
	bool b2 = Input_iterator<ostream_iterator<char>>();
	bool b3 = Input_iterator<forward_list<int>::const_iterator>();
	bool b4 = Input_iterator<forward_list<int>::iterator>();
	bool b5 = Input_iterator<list<int>::const_iterator>();
	bool b6 = Input_iterator<list<int>::iterator>();
	bool b7 = Input_iterator<vector<int>::const_iterator>();
	bool b8 = Input_iterator<vector<int>::iterator>();
	bool b9 = Input_iterator<const int*>();
	bool b10 = Input_iterator<int*>();


	cout << boolalpha;
	cout << "Input_iterator<istream_iterator<char>>(): " << b1 << endl;
	cout << "Input_iterator<ostream_iterator<char>>(): " << b2 << endl;
	cout << "Input_iterator<forward_list<int>::const_iterator>(): " << b3 << endl;
	cout << "Input_iterator<forward_list<int>::iterator>(): " << b4 << endl;
	cout << "Input_iterator<list<int>::const_iterator>(): " << b5 << endl;
	cout << "Input_iterator<list<int>::iterator>(): " << b6 << endl;
	cout << "Input_iterator<vector<int>::const_iterator>(): " << b7 << endl;
	cout << "Input_iterator<vector<int>::iterator>(): " << b8 << endl;
	cout << "Input_iterator<const int*>(): " << b9 << endl;
	cout << "Input_iterator<int*>(): " << b10 << endl;
}

