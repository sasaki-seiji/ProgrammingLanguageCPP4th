/*
 * address_constexpr.cpp
 *
 *  Created on: 2016/04/29
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

constexpr const char* p1 = "asdf";
constexpr const char* p2 = p1;
constexpr const char* p3 = p1+2;
constexpr char c = p1[2];

int main()
{
	cout << "p1: " << p1 << '\n';
	cout << "p2: " << p2 << '\n';
	cout << "p3: " << p3 << '\n';
	cout << "c: " << c << '\n';
}
