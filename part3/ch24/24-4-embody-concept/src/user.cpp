/*
 * user.cpp
 *
 *  Created on: 2017/06/11
 *      Author: sasaki
 */


#include "String.h"
#include <memory>
#include <string>
#include <utility>
#include <complex>
#include <iostream>
using namespace std;

String<int> si;
String<string> ss;
//String<complex<double>> sc;
	// error: static assertion failed: String's character type is not ordered
String<pair<int,char>> sp;
//String<unique_ptr<int>> sup;
	// error: static assertion failed: String's character type is not ordered

static_assert(Ordered<std::string>(), "std::string is not Ordered");
static_assert(Ordered<String<char>>(), "String<char> is not Ordered");

int main()
{
	si += 100;
	cout << si << endl;

	sp += pair<int,char>(100,'A');
	//cout << sp << endl;
		// error: static assertion failed: String's character not streamable

	String<pair<int,char>> sp2;
	sp2 += pair<int,char>(100,'B');
	cout << boolalpha;
	cout << "(100,'A') < (100,'B') ? " << (sp < sp2) << endl;
}

