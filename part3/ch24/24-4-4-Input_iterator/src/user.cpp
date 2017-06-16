/*
 * user.cpp
 *
 *  Created on: 2017/06/16
 *      Author: sasaki
 */

#include "input_iterator.h"
using namespace Estd;

#include <typeinfo>
#include <iterator>
#include <forward_list>
#include <iostream>
using namespace std;

int main()
{
	bool b1 = Input_iterator<istream_iterator<char>>();
	bool b2 = Input_iterator<ostream_iterator<char>>();
	bool b3 = Input_iterator<forward_list<int>::const_iterator>();
	bool b4 = Input_iterator<forward_list<int>::iterator>();

	cout << "Dereference_result<istream_iterator<char>>: "
			<< typeid(Dereference_result<istream_iterator<char>>).name() << endl;
	cout << "Iterator_value_type_result<istream_iterator<char>>: "
			<< typeid(Iterator_value_type_result<istream_iterator<char>>).name() << endl;

	cout << boolalpha;
	cout << "Input_iterator<istream_iterator<char>>(): " << b1 << endl;
	cout << "Input_iterator<ostream_iterator<char>>(): " << b2 << endl;
	cout << "Input_iterator<forward_list<int>::const_iterator>(): " << b3 << endl;
	cout << "Input_iterator<forward_list<int>::iterator>(): " << b4 << endl;
}

