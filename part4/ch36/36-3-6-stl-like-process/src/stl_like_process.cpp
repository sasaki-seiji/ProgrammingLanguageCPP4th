/*
 * stl_like_process.cpp
 *
 *  Created on: 2016/12/20
 *      Author: sasaki
 */


#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <cassert>
using namespace std;

void f(string& s)
{
	//auto p = find_if(s.begin(), s.end(), islower);
	auto p = find_if(s.begin(), s.end(), [](char c) { return islower(c); });
	cout << "*p: " << *p << endl;
}

void add_middle(string& s, const string& middle)
{
	auto p = s.find(' ');
	s.insert(p, ' '+middle);
}

void test()
{
	string dmr = "Dennis Ritchie";
	add_middle(dmr, "MacAlistair");
	cout << dmr << '\n';
}

void f()
{
	string s = "but I have heard it works even if you don't believe in it";
	s.replace(0,4,"");
	s.replace(s.find("even"),4,"only");
	s.replace(s.find(" don't"),6,"");
	assert(s=="I have heard it works only if you believe in it");
	cout << s << endl;
}

void f2()
{
	string s = "but I have heard it works even if you don't believe in it";
	s.replace(0,4,"").replace(s.find("even"),4,"only")
					.replace(s.find(" don't"),6,"");
	//assert(s=="I have heard it works only if you believe in it");
	cout << s << endl;
}

int main()
{
	string s {"ABC DEF XYZ 012 abc"};
	f(s);

	test();

	f();
	f2();
}
