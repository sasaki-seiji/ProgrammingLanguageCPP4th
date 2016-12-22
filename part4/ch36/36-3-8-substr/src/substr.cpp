/*
 * substr.cpp
 *
 *  Created on: 2016/12/20
 *      Author: sasaki
 */


#include <string>
#include <iostream>
using namespace std;

void user()
{
	string s = "Mary had a little lamb";
	string s2 = s.substr(0,4);
	s2 = "Rose";

	cout << "s: " << s << endl;
	cout << "s2: " << s2 << endl;
}

void f()
{
	string s = "Mary had a little lamb";
	string s2 = s.substr(0,4);
	auto i1 = s.compare(s2);
	auto i2 = s.compare(0,4,s2);

	cout << "i1: " << i1 << endl;
	cout << "i2: " << i2 << endl;

}

int main()
{
	user();
	f();
}
