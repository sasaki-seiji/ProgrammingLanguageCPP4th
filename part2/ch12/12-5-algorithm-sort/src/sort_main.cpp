/*
 * sort_main.cpp
 *
 *  Created on: 2016/05/11
 *      Author: sasaki
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


struct User {
	const char* name;
	const char* id;
	int dept;
};

vector<User> heads = {
	{"Ritchie D.M.",	"dmr",	11271},
	{"Sethi R.",		"ravi",	11272},
	{"Szymanski T.G.",	"tgs",	11273},
	{"Schryer N.L.",	"nls",	11274},
	{"Schryer N.L.",	"nls",	11275},
	{"Kernighan B.W.",	"bwk",	11276}
};

void print_id(vector<User>& v)
{
	for (auto& x : v)
		cout << x.name << '\t' << x.id << '\t' << x.dept << '\n';
}

int main()
{
	cout << "Heads in alphabetical order:\n";
	sort(heads.begin(), heads.end(),
			// 2016.05.11 change for bug
			//[](const User& x, const User& y) { return x.name < y.name; });
			[](const User& x, const User& y) { return strcmp(x.name, y.name); });
	print_id(heads);
	cout << '\n';

	cout << "Heads in order of department number:\n";
	sort(heads.begin(), heads.end(),
			[](const User& x, const User& y) { return x.dept < y.dept; });
	print_id(heads);
}

