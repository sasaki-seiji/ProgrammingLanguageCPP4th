/*
 * user.cpp
 *
 *  Created on: 2016/10/14
 *      Author: sasaki
 */


#include "Tuple.h"
#include <iostream>
using namespace std;

int main()
{
	auto xxxx = make_tuple(1.2, 3, 'x', 1223);
	cout << "xxxx: " << xxxx << "\n";
	auto xxx = make_tuple(3, 'x', 1223);
	cout << "xxx: " << xxx << "\n";
	auto xx = make_tuple('x', 1223);
	cout << "xx: " << xx << "\n";
	auto x = make_tuple(1223);
	cout << "x: " << x << "\n";

	auto null_tuple = make_tuple();
	cout << "null: " << null_tuple << endl;
}

