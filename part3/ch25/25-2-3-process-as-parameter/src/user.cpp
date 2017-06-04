/*
 * user.cpp
 *
 *  Created on: 2016/09/18
 *      Author: sasaki
 */

#include "Map.h"

#include <string>
//#include <cstring>
#include <strings.h> // for Linux
#include <iostream>
using namespace std;

Map<string,int> m1;
Map<string,int,std::greater<string>> m2;

struct Complex_compare {
	string str;
	int i;
	bool operator()(const string& a, const string& b) { return a < b; }
};
Complex_compare f3 {"French", 3};
Map<string,int,Complex_compare> m3 {f3};

using Cmp = bool(*)(const string&, const string&);
bool insensitive(const string& a, const string& b);
Map<string,int,Cmp> m4{insensitive};
Map<string,int,Cmp> m5
	{[](const string& a, const string& b){ return a>b;} };

bool insensitive(const string& a, const string& b)
{
	//return stricmp(a.c_str(), b.c_str()) < 0;
	return strcasecmp(a.c_str(), b.c_str()) < 0; // for Linux
}

//Map<string, int, [](const string& x, const string& y) { return x<y; }> c3;
	// error: lambda-expression in template-argument

//auto cmp = [](const string& x, const string& y) const { return x<y; };
	// error: expected '{' before 'const'
auto cmp = [](const string& x, const string& y) { return x<y; };
Map<string,int,decltype(cmp)> c4 {cmp};

void print_typeids()
{
	cout << "-- print_typeids() --\n";
	cout << "typeids(Map<string,int>): " << typeid(m1).name() << endl;
	cout << "typeids(Map<string,int,std::greater<string>>): " << typeid(m2).name() << endl;
	cout << "typeids(Map<string,int,Complex_compare>): " << typeid(m3).name() << endl;
	cout << "typeids(Map<string,int,Cmp>{insensitive}): " << typeid(m4).name() << endl;
	cout << "typeids(Map<string,int,Cmp>{}): " << typeid(m5).name() << endl;
	cout << "typeids(Map<string,int,decltype(cmp)>): " << typeid(c4).name() << endl;

}

static const char* a[] = {
	"map", "string", "int", "std", "greater", "String", "Map"
};

template<typename M>
void test_Map(M& m, const char* title)
{
	int i = 0;
	for (auto x : a) {
		m[x] = i;
		i += 10;
	}

	cout << title << endl;
	m.print(cout);
}

// add main

int main()
{
	print_typeids();

	test_Map(m1, "m1: Map<string,int>");
	test_Map(m2, "m2: Map<string,int,std::greater<string>>");
	test_Map(m3, "m3{f3}: Map<string,int,Complex_compare>");
	test_Map(m4, "m4{insensitive}: Map<string,int,Cmp>");
	test_Map(m5, "m5{lambda}: Map<string,int,Cmp>");
	test_Map(c4, "c4{cmp}: Map<string,int,decltype(cmp)>");
}

