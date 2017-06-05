/*
 * template_as_parameter.cpp
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */

#include "Xrefd.h"
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

};

#if 0
Xrefd<Record,My_container> x2;
#endif

static const Entry entries[] = {
	{10, "012"}, {1, "abc"}, {2, "xyz"}, {101, "ABCD"}, {99, "XYZ"}
};

void test_Xrefd()
{
	cout << "-- test_Xrefd() --\n";

	for (const auto& x : entries)
		x1.add(x);
	x1.make_ref();

	cout << "- sort by id -\n";
	x1.sort_ref(Comp_by_id<Entry>{});
	for (auto e : x1)
		cout << *e << endl;

	cout << "- sort by name -\n";
	x1.sort_ref(Comp_by_name<Entry>{});
	for (auto e : x1)
		cout << *e << endl;
}

template<typename C, typename C2>
class Xrefd2 {
	C mems;
	C2 refs;
};
Xrefd2<vector<Entry>, set<Entry*>> x;

// add main

int main()
{
	test_Xrefd();
}
