/*
 * user.cpp
 *
 *  Created on: 2016/09/18
 *      Author: sasaki
 */

#include "map.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

map<string,int> m1;
map<string,int,std::greater<string>> m2;

struct Complex_compare {
	string str;
	int i;
	bool operator()(const string& a, const string& b) { return a < b; }
};
Complex_compare f3 {"French", 3};
map<string,int,Complex_compare> m3 {f3};

using Cmp = bool(*)(const string&, const string&);
bool insensitive(const string& a, const string& b);
map<string,int,Cmp> m4{insensitive};
map<string,int,Cmp> m5
	{[](const string& a, const string& b){ return a>b;} };

bool insensitive(const string& a, const string& b)
{
	return stricmp(a.c_str(), b.c_str()) < 0;
}

//map<string, int, [](const string& x, const string& y) const { return x<y; }> c3;
	// error: lambda-expression in template-argument

//auto cmp = [](const string& x, const string& y) const { return x<y; };
	// error: expected '{' before 'const'
auto cmp = [](const string& x, const string& y) { return x<y; };
map<string,int,decltype(cmp)> c4 {cmp};

// add main

int main()
{
	cout << "m1: less<string>:\n";
	m1["map"] = 10;
	m1["string"] = 20;
	m1["int"] = 30;
	m1["std"] = 40;
	m1["greater"] = 50;
	m1["string"] = 60;
	m1["m2"] = 70;

	m1.print(cout);

	cout << "m2: greater<string>:\n";
	m2["map"] = 10;
	m2["string"] = 20;
	m2["int"] = 30;
	m2["std"] = 40;
	m2["greater"] = 50;
	m2["string"] = 60;
	m2["m2"] = 70;

	m2.print(cout);

	cout << "m3: Complex_compare{f3}:\n";
	m3["map"] = 10;
	m3["string"] = 20;
	m3["int"] = 30;
	m3["std"] = 40;
	m3["greater"] = 50;
	m3["string"] = 60;
	m3["m2"] = 70;

	m3.print(cout);

	cout << "m4: insensitive:\n";
	m4["map"] = 10;
	m4["string"] = 20;
	m4["int"] = 30;
	m4["Cmp"] = 40;
	m4["m5"] = 50;
	m4["const"] = 60;
	m4["string"] = 70;
	m4["a"] = 80;
	m4["const"] = 90;
	m4["string"] = 100;
	m4["b"] = 110;
	m4["return"] = 120;

	m4.print(cout);

	cout << "m5: lambda:\n";
	m5["map"] = 10;
	m5["string"] = 20;
	m5["int"] = 30;
	m5["Cmp"] = 40;
	m5["m5"] = 50;
	m5["const"] = 60;
	m5["string"] = 70;
	m5["a"] = 80;
	m5["const"] = 90;
	m5["string"] = 100;
	m5["b"] = 110;
	m5["return"] = 120;

	m5.print(cout);

	cout << "c4: decltype(lambda):\n";

	c4["map"] = 10;
	c4["string"] = 20;
	c4["int"] = 30;
	c4["Cmp"] = 40;
	c4["m5"] = 50;
	c4["const"] = 60;
	c4["string"] = 70;
	c4["a"] = 80;
	c4["const"] = 90;
	c4["string"] = 100;
	c4["b"] = 110;
	c4["return"] = 120;

	c4.print(cout);
}

