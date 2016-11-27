/*
 * compare_criteria.cpp
 *
 *  Created on: 2016/11/24
 *      Author: sasaki
 */

#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Nocase {
public:
	bool operator()(const string&, const string&);
};

bool Nocase::operator()(const string& x, const string& y)
{
	auto p = x.begin();
	auto q = y.begin();

	while (p!=x.end() && q!=y.end() && toupper(*p)==toupper(*q)) {
		++p;
		++q;
	}

	if (p == x.end()) return q != y.end();
	if (q == y.end()) return false;
	return toupper(*p) < toupper(*q);
}

struct Cstring_less {
	bool operator()(const char* p, const char* q) const { return strcmp(p,q)<0 ;}
};

template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1,T2> p)
{
	return os << '(' << p.first << ',' << p.second << ')';
}

template<typename Iter>
void print(ostream& os, Iter start, Iter last)
{
	for ( ;start != last; ++start)
		os << *start << ' ';
	os << endl;
}

int main()
{
	vector<string> fruit {"apple", "pear", "Apple", "Pear", "lemon" };

	sort(fruit.begin(), fruit.end(), Nocase());
	print(cout, fruit.begin(), fruit.end());

	sort(fruit.begin(), fruit.end());
	print(cout, fruit.begin(), fruit.end());

	//map<char*,int,Cstring_less> m;
	map<const char*,int,Cstring_less> m;

	m["apple"] = 1;
	m["pear"] = 2;
	m["Apple"] = 3;
	m["Pear"] = 4;
	m["lemon"] = 5;
	print(cout, m.begin(), m.end());
}
