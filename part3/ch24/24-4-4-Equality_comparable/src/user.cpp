/*
 * user.cpp
 *
 *  Created on: 2017/06/18
 *      Author: sasaki
 */



#include "equality_comparable.h"
using namespace Estd;

#include <vector>
#include <iostream>
#include <memory>
using namespace std;

int main()
{
	bool b1 = Equality_comparable<int>();
	bool b2 = Equality_comparable<vector<int>>();
	bool b3 = Equality_comparable<unique_ptr<int>>();
	bool b4 = Equality_comparable<istream>();

	cout << boolalpha;
	cout << "Equality_comparable<int>(): " << b1 << endl;
	cout << "Equality_comparable<vector<int>>(): " << b2 << endl;
	cout << "Equality_comparable<unique_ptr<int>>(): " << b3 << endl;
	cout << "Equality_comparable<istream>(): " << b4 << endl;
}
