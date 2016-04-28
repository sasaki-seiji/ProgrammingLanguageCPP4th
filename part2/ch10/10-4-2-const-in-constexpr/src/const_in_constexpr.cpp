/*
 * const_in_constexpr.cpp
 *
 *  Created on: 2016/04/26
 *      Author: sasaki
 */

#include <string>
#include <cmath>
#include <iostream>
using namespace std;


const int x = 7;
const string s = "asdf";
const int y = sqrt(x);

constexpr int xx = x;
//constexpr string ss = s;
	// the type 'const string {aka const std::__cxx11::basic_string<char>}' of constexpr variable 'ss' is not literal
constexpr int yy = y;

int main()
{
	cout << "y: " << y << '\n';
	cout << "yy: " << yy << '\n';
}
