/*
 * predicate.cpp
 *
 *  Created on: 2016/04/03
 *      Author: sasaki
 */

#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

struct Greater_than {
	int val;
	Greater_than(int v) : val{v} { }
	bool operator()(const pair<string,int>& r) { return r.second > val; }
};
void f(map<string,int>& m)
{
	auto p = find_if(m.begin(), m.end(), Greater_than{42});
	cout << "found : " << p->first << " - " << p->second << '\n';
}

void f2(map<string,int>& m)
{
	auto p = find_if(m.begin(), m.end(),
			[](const pair<string,int>& r){ return r.second>42; });
	cout << "found : " << p->first << " - " << p->second << '\n';
}

int main()
{
	map<string,int> m ={
		{ "this",	3 },
		{ "is",		10 },
		{ "a" ,		26 },
		{ "map",	34 },
		{ "with",	51 },
		{ "string", 26 },
		{ "key",	40 }
	};

	cout << "calling f(m)\n";
	f(m);
	cout << "calling f2(m)\n";
	f2(m);
}
