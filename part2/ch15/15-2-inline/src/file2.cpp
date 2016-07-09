/*
 * file2.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */


inline int f(int i) { return i+1; }

extern inline int g(int i) { return i+1; }

int h(int);

// add main
#include <iostream>
using namespace std;
int main()
{
	cout << "f(2) : " << f(2) << '\n';
	cout << "g(2) : " << g(2) << '\n';
	cout << "h(2) : " << h(2) << '\n';
}
