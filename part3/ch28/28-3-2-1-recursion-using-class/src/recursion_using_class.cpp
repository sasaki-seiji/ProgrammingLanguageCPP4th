/*
 * recursion_using_class.cpp
 *
 *  Created on: 2016/10/07
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

template<int N>
struct Fac {
	static const int value = N*Fac<N-1>::value;
};

template<>
struct Fac<1> {
	static const int value = 1;
};

constexpr int x7 = Fac<7>::value;

// add main

int main()
{
	cout << "x7: " << x7 << '\n';
}

