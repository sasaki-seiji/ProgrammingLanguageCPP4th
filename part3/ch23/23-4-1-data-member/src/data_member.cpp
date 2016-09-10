/*
 * data_member.cpp
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */


#include <string>
#include <iostream>
using namespace std;

template<typename T>
struct X {
	int m1 = 7;
	T m2;
	X(const T&x) : m2{x} { }
};

X<int> xi {9};
X<string> xs {"Rapperswil"};

int main()
{
	cout << "xi.m1: " << xi.m1 << '\n';
	cout << "xi.m2: " << xi.m2 << '\n';
	cout << "xs.m1: " << xs.m1 << '\n';
	cout << "xs.m2: " << xs.m2 << '\n';
}
