/*
 * user.cpp
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#include "range.h"
using namespace Estd;

#include <vector>
#include <list>
#include <array>
#include <iostream>
using namespace std;

#include "List.h"

int main()
{
	bool b1 = Range<vector<int>>();
	bool b2 = Range<list<int>>();
	bool b3 = Range<array<int,10>>();
	bool b4 = Range<List<int>>();
	bool b5 = Range<int>();

	cout << boolalpha;
	cout << "Range<vector<int>>(): " << b1 << endl;
	cout << "Range<list<int>>(): " << b2 << endl;
	cout << "Range<array<int,10>>(): " << b3 << endl;
	cout << "Range<List<int>>(): " << b4 << endl;
	cout << "Range<int>(): " << b5 << endl;
}

