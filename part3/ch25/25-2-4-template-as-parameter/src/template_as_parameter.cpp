/*
 * template_as_parameter.cpp
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */

#include "Xrefd.h"
#include "Xrefd2.h"
#include "Entry.h"
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

template<typename T>
using My_vec = vector<T>;


Xrefd<Entry,My_vec> x1;

template<typename T>
class My_container {
	vector<T> v;
public:
	using iterator = typename vector<T>::iterator;
	void push_back(const T& x) { v.push_back(x); }
	void clear() { v.clear(); }
	iterator begin() { return v.begin(); }
	iterator end() { return v.end(); }
};

Xrefd<Record,My_container> x2;

static const Entry entries[] = {
	{10, "012"}, {1, "abc"}, {2, "xyz"}, {101, "ABCD"}, {99, "XYZ"}
};

static const Record records[] = {
	//int id; std::string name; int phone; std::string addr;
	{ 21, "123", 123456789, "kawasaki"},
	{ 123, "abc", 987654321, "chino"},
	{ 11, "XYZ", 1231234567, "chino"},
	{ 34, "xyz012", 234567890, "hiroshima"},
	{ 46, "sasaki", 345678901, "kawasaki"},
	{ 99, "sophia", 456789012, "chino"}
};

void test_Xrefd()
{
	cout << "-- test_Xrefd() --\n";

	for (const auto& x : entries)
		x1.add(x);
	x1.make_ref();

	cout << "- initial x1 -\n";
	for (auto e : x1)
		cout << *e << endl;

	cout << "- x1: sort by id -\n";
	x1.sort_ref(Comp_by_id<Entry>{});
	for (auto e : x1)
		cout << *e << endl;

	cout << "- x1: sort by name -\n";
	x1.sort_ref(Comp_by_name<Entry>{});
	for (auto e : x1)
		cout << *e << endl;

	for (const auto& x : records)
		x2.add(x);
	x2.make_ref();

	cout << "- initial x2 -\n";
	for (auto e : x2)
		cout << *e << endl;

	cout << "- x2: sort by id -\n";
	x2.sort_ref(Comp_by_id<Record>{});
	for (auto e : x2)
		cout << *e << endl;

	cout << "- x2: sort by name -\n";
	x2.sort_ref(Comp_by_name<Record>{});
	for (auto e : x2)
		cout << *e << endl;

	cout << "- x2: sort by phone -\n";
	x2.sort_ref(Comp_by_phone<Record>{});
	for (auto e : x2)
		cout << *e << endl;

	cout << "- x2: sort by addr -\n";
	x2.sort_ref(Comp_by_addr<Record>{});
	for (auto e : x2)
		cout << *e << endl;
}

Xrefd2<vector<Entry>, set<Entry*,Comp_by_id<Entry>>> x;


void test_Xrefd2()
{
	cout << "-- test_Xrefd2() --\n";

	for (const auto& e : entries)
		x.add(e);
	x.make_ref();

	cout << "- initial x -\n";
	for (auto e : x)
		cout << *e << endl;
}

// add main

int main()
{
	test_Xrefd();
	test_Xrefd2();
}
