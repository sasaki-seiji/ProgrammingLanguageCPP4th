/*
 * unique.cpp
 *
 *  Created on: 2016/11/29
 *      Author: sasaki
 */


#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto& x : v)
		os << x << ", ";
	return os;
}



void test(list<string>& ls, vector<string>& vs)
{
	ls.sort();
	unique_copy(ls.begin(), ls.end(), back_inserter(vs));
}

void bad(vector<string>& vs)
{
	sort(vs.begin(), vs.end());
	cout << "vs: " << vs << endl;
	unique(vs.begin(), vs.end());
}

template<typename C>
void eliminate_duplicate(C& c)
{
	sort(c.begin(), c.end());
	auto p = unique(c.begin(), c.end());
	c.erase(p, c.end());
}

int main()
{
	list<string> ls { "abc", "xyz", "012", "abc", "012", "xyz", "ABC" };
	vector<string> vs;
	test(ls, vs);
	cout << "vs: " << vs << endl;

	vector<string> vs2 { "abc", "xyz", "012", "abc", "012", "xyz", "ABC" };
	bad(vs2);
	cout << "vs2: " << vs2 << endl;

	string s = "abbcccde";
	auto p = unique(s.begin(), s.end());
	cout << s << ' ' << p-s.begin() << endl;

	vector<string> vs3 { "abc", "xyz", "012", "abc", "012", "xyz", "ABC" };
	eliminate_duplicate(vs3);
	cout << "vs3: " << vs3 << endl;
}
