/*
 * user.cpp
 *
 *  Created on: 2017/06/21
 *      Author: sasaki
 */

#include "movable.h"
using namespace Estd;

#include <memory>
#include <iostream>
using namespace std;

int main()
{
	bool b1 = Movable<int>();
	bool b2 = Movable<unique_ptr<int>>();
	bool b3 = Movable<istream>();
	bool b4 = Movable<type_info>();

	cout << boolalpha;
	cout << "Movable<int>(): " << b1 << endl;
	cout << "Movable<unique_ptr<int>>(): " << b2 << endl;
	cout << "Movable<istream>(): " << b3 << endl;
	cout << "Movable<type_info>(): " << b4 << endl;
}
