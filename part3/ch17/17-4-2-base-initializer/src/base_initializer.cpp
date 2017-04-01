/*
 * base_initializer.cpp
 *
 *  Created on: 2016/07/28
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct B1 { B1() { cout << "B1()\n"; } };
struct B2 { B2(int i) { cout << "B2(" << i << ")\n"; } };

struct D1 : B1, B2 {
	D1(int i) : B1{}, B2{i} { cout << "D1(" << i << ")\n"; }
};

struct D2 : B1, B2 {
	D2(int i) : B2{i} { cout << "D2(" << i << ")\n"; }
};

struct D3 : B1, B2 {
	//D3(int i) { }
		// error: no matching function for call to 'B2::B2()'
};

// add main

int main()
{
	D1 d1(10);
	D2 d2(20);
}


