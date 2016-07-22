/*
 * introduce.cpp
 *
 *  Created on: 2016/07/22
 *      Author: sasaki
 */

#include <string>
#include <iostream>
using namespace std;

string ident(string arg)
{
	return arg;
}

int main()
{
	string s1 {"Adams"};
	s1 = ident(s1);

	string s2 {"Pratchett"};
	s1 = s2;

	cout << "s1: " << s1 << '\n';
	cout << "s2: " << s2 << '\n';
}

