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
#include <iostream>
using namespace std;

int main()
{
	bool b1 = Copyable<int>();
	bool b2 = Copyable<vector<int>>();
	bool b3 = Copyable<unique_ptr<int>>();
	bool b4 = Copyable<istream>();
	bool b5 = Copyable<type_info>();

	cout << boolalpha;
	cout << "Copyable<int>(): " << b1 << endl;
	cout << "Copyable<vector<int>>(): " << b2 << endl;
	cout << "Copyable<unique_ptr<int>>(): " << b3 << endl;
	cout << "Copyable<istream>(): " << b4 << endl;
	cout << "Copyable<type_info>(): " << b5 << endl;
}
