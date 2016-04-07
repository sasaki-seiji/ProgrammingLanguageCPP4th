/*
 * pair_tuple.cpp
 *
 *  Created on: 2016/04/07
 *      Author: sasaki
 */

#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iostream>
using namespace std;

struct Record
{
	string	name;
	int		phone;
};

ostream& operator<<(ostream& os, const Record& r)
{
	os << "{" << r.name << "," << r.phone << "}\n";
	return os;
}

auto rec_lt = [](const Record& r1, const Record& r2)
		{ return r1.name < r2.name; };

void f(const vector<Record>& v)
{
	auto er = equal_range(v.begin(), v.end(), Record{"Reg"}, rec_lt);
	for (auto p = er.first; p != er.second; ++p)
		cout << *p;
}

void f(vector<string>& v)
{
	auto pp = make_pair(v.begin(), 2);

	cout << "*pp.first = " << *pp.first << ", pp.second = " << pp.second << '\n';
}

int main()
{
	vector<Record> vr = {
		{ "sasaki", 51994582 },
		{ "sasaki", 7525790 },
		{ "Reg",	1234567 },
		{ "sophia", 12345678 },
		{ "Reg",	98765432 },
		{ "lisa",   98765432 }
	};
	sort(vr.begin(), vr.end(), rec_lt);
	f(vr);

	vector<string> vs = { "sasaki", "Reg", "sophia", "lisa", "sasaki", "Reg" };
	f(vs);

	tuple<string, int, double> t2 {"Sild", 123, 3.14};
	auto t = make_tuple(string{"Herring"}, 10, 1.23);

	string s = get<0>(t);
	int x = get<1>(t);
	double d = get<2>(t);

	cout << "s: " << s << ", x: " << x << ", d: " << d << '\n';
}

