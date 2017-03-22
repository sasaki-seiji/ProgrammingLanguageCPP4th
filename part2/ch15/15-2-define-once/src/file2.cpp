/*
 * file2.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */


int x;
	// `x' が複数定義されています
extern double b;
extern int c;

// add main
#include <iostream>
using namespace std;
int main()
{
	cout << "x : " << x << '\n'; // multiple definition of `x'
	cout << "b : " << b << '\n';
	cout << "c : " << c << '\n'; // undefined reference to `c'
		// `c' に対する定義されていない参照です
}
