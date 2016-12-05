/*
 * bitset_constructor.cpp
 *
 *  Created on: 2016/12/05
 *      Author: sasaki
 */

#include <bitset>
#include <iostream>
using namespace std;

void f()
{
	bitset<10> b1;
	cout << "b1: " << b1 << endl;

	bitset<16> b2 = 0xaaaa;
	cout << "b2: " << b2 << endl;

	bitset<32> b3 = 0xaaaa;
	cout << "b3: " << b3 << endl;

	bitset<10> b4 {"1010101010"};
	cout << "b4: " << b4 << endl;

	bitset<10> b5 {"10110111011110",4};
	cout << "b5: " << b5 << endl;

	bitset<10> b6 {string("1010101010")};
	cout << "b6: " << b6 << endl;

	bitset<10> b7 {string("10110111011110"),4};
	cout << "b7: " << b7 << endl;

	bitset<10> b8 {string("10110111011110"),2,8};
	cout << "b8: " << b8 << endl;

	try {
		bitset<10> b9 {string("n0g00d")};
		cout << "b9: " << b9 << endl;
	} catch (invalid_argument& e) {
		cerr << "invalid_argument: " << e.what() << endl;
	}

	//bitset<10> b10 = string{"101001"};
		// error: conversion from 'std::__cxx11::string {aka std::__cxx11::basic_string<char>}' to non-scalar type 'std::bitset<10ull>' requested
}

int main()
{
	f();
}
