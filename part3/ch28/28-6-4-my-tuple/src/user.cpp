/*
 * user.cpp
 *
 *  Created on: 2017/05/30
 *      Author: sasaki
 */

#include "my_tuple.h"
#include "my_tuple_util.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void test_head_tail()
{
	cout << "-- test_head_tail() --\n";

	my_tuple<string,vector<int>,double> tt("hello", {1,2,3,4}, 1.2);
	string h = head(tt);
	my_tuple<vector<int>,double> t2 = tail(tt);
	vector<int> v = head(t2);
	my_tuple<double> t3 = tail(t2);
	double d = head(t3);

	cout << "h: " << h << endl;
	cout << "v.size(): " << v.size() << endl;
	cout << "d: " << d << endl;

	const my_tuple<string,vector<int>,double> ctt("hello", {1,2,3,4}, 1.2);
	const string& ch = head(tt);
	const my_tuple<vector<int>,double>& ct2 = tail(ctt);
	const vector<int>& cv = head(ct2);
	const my_tuple<double>& ct3 = tail(ct2);
	double cd = head(ct3);

	cout << "ch: " << ch << endl;
	cout << "cv.size(): " << cv.size() << endl;
	cout << "cd: " << cd << endl;
}

void test_make_tuple()
{
	cout << "-- test_make_tuple() --\n";

	auto t = my_make_tuple("Hello tuple", 43, 3.15);
	double d = my_get<2>(t);

	cout << "d: " << d << endl;
}

void user()
{
	cout << "-- user() --\n";

	cout << my_make_tuple() << endl;
	cout << my_make_tuple("One meatbool!") << endl;
	cout << my_make_tuple(1, 1.2, "Tail!") << endl;
}

int main()
{
	test_head_tail();
	test_make_tuple();
	user();
}
