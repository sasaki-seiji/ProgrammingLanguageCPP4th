/*
 * main.cpp
 *
 *  Created on: 2016/05/21
 *      Author: sasaki
 */

#include <iostream>
#include <string>
using namespace std;
#include "vector.h"

int main()
{
	const int	sz = 100*1000;
	string str;
	for (int i; i < 100; ++i) str += 'z';

	try {
		vector<int> vi(sz);
		cout << "success alloc vector<int>(" << sz << ")\n" << flush;

		vector<string> vs(sz, str);
		cout << "success alloc vector<string>(" << sz << ")\n" << flush;
	}
	catch (...) {
		cerr << "fail alloc\n" << flush;
	}
}
