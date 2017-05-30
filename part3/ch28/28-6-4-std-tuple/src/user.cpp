/*
 * user.cpp
 *
 *  Created on: 2017/05/30
 *      Author: sasaki
 */

#include "tuple_util.h"
#include <tuple>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void test_head_tail()
{
	cout << "-- test_head_tail() --\n";

	tuple<string,vector<int>,double> tt("hello", {1,2,3,4}, 1.2);
	string h = head(tt);
	tuple<vector<int>,double> t2 = tail(tt);
	vector<int> v = head(t2);
	tuple<double> t3 = tail(t2);
	double d = head(t3);

	cout << "h: " << h << endl;
	cout << "v.size(): " << v.size() << endl;
	cout << "d: " << d << endl;

	const tuple<string,vector<int>,double> ctt("hello", {1,2,3,4}, 1.2);
	const string& ch = head(tt);
	const tuple<vector<int>,double>& ct2 = tail(ctt);
	const vector<int>& cv = head(ct2);
	const tuple<double>& ct3 = tail(ct2);
	double cd = head(ct3);

	cout << "ch: " << ch << endl;
	cout << "cv.size(): " << cv.size() << endl;
	cout << "cd: " << cd << endl;

}

void test_make_tuple()
{
	cout << "-- test_make_tuple() --\n";

	auto t = make_tuple("Hello tuple", 43, 3.15);
	double d = get<2>(t);

	cout << "d: " << d << endl;
}

void user()
{
	cout << "-- user() --\n";

	cout << make_tuple() << endl;
	cout << make_tuple("One meatbool!") << endl;
	cout << make_tuple(1, 1.2, "Tail!") << endl;
}

int main()
{
	test_head_tail();
	test_make_tuple();
	user();
}
