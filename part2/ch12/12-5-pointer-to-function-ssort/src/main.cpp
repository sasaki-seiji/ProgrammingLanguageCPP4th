/*
 * main.cpp
 *
 *  Created on: 2016/05/11
 *      Author: sasaki
 */


#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

#include "ssort.h"

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

int cmp1(const void* p, const void* q)
{
	return strcmp(static_cast<const User*>(p)->name,
					static_cast<const User*>(q)->name);
}

int cmp2(const void* p, const void* q)
{
	return static_cast<const User*>(p)->dept - static_cast<const User*>(q)->dept;
}

int cmp3(const User* p, const User* q)
{
	return strcmp(p->id, q->id);
}

int main()
{
	cout << "Heads in alphabetical order:\n";
	ssort(&heads[0], 6, sizeof(User), cmp1);
	print_id(heads);
	cout << '\n';

	cout << "Heads in order of department number:\n";
	ssort(&heads[0], 6, sizeof(User), cmp2);
	print_id(heads);
}
