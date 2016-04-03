/*
 * iterator.cpp
 *
 *  Created on: 2016/04/03
 *      Author: sasaki
 */

#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

bool has_c(const string& s, char c)
{
	auto p = find(s.begin(), s.end(), c);
	if (p != s.end())
		return true;
	else
		return false;
}

bool has_c2(const string& s, char c)
{
	return find(s.begin(), s.end(), c) != s.end();
}

vector<string::iterator> find_all(string& s, char c)
{
	vector<string::iterator> res;
	for (auto p = s.begin(); p != s.end(); ++p)
		if (*p == c)
			res.push_back(p);
	return res;
}

void test()
{
	string m {"Many had a little lamb"};
	for (auto p : find_all(m, 'a'))
		if (*p != 'a')
			cerr << "a bug!\n";

	// 2016.04.03 add
	cout << "string m have " << find_all(m, 'a').size() << " 'a's\n";
}

template<typename C, typename V>
vector<typename C::iterator> find_all(C& c, V v)
{
	vector<typename C::iterator> res;
	for (auto p = c.begin(); p != c.end(); ++p)
		if (*p == v)
			res.push_back(p);
	return res;
}

template<typename C>
void print_values(ostream& os, const C& c)
{
	for (auto& x : c)
		os << x << '\n';
}

void test2()
{
	string m {"Many had a litle lamb"};
	for (auto p : find_all(m, 'a'))
		if (*p != 'a')
			cerr << "string bug!\n";

	list<double> ld {1.1, 2.2, 3.3, 1.1};
	for (auto p : find_all(ld, 1.1))
		if (*p != 1.1)
			cerr << "list bug!\n";

	vector<string> vs {"red", "blue", "green", "green", "orange", "green" };
	for (auto p : find_all(vs, "red"))
		if (*p != "red")
			cerr << "vector bug!\n";

	for (auto p : find_all(vs, "green"))
		*p = "vert";

	cout << "vector<string> vs turns:\n";
	print_values(cout, vs);
}

int main()
{
	string	s {"this is a string" };

	cout << "has_c(s, 'i') returns : " << has_c(s, 'i') << '\n';
	cout << "has_c2(s, 'i') returns : " << has_c2(s, 'i') << '\n';

	cout << "calling test()\n";
	test();

	cout << "calling test2()\n";
	test2();
}
