/*
 * copy.cpp
 *
 *  Created on: 2016/11/29
 *      Author: sasaki
 */


#include <algorithm>
#include <list>
#include <iostream>
#include <iterator>
using namespace std;

struct Club {
	string name;
	string founded;
};

ostream& operator<<(ostream& os, const Club& c)
{
	os << "{name=" << c.name << ", founded=" << c.founded << "} ";
	return os;
}

void f(list<Club>& lc, ostream& os)
{
	copy(lc.begin(), lc.end(), ostream_iterator<Club>(os));
}

void f(const vector<int>& vs, vector<int>& v)
{
	copy(vs.begin(), vs.end(), v.begin());
	copy(vs.begin(), vs.end(), back_inserter(v));
}

void f2(list<int>& ld, int n, ostream& os)
{
	copy_if(ld.begin(), ld.end(),
			ostream_iterator<int>(os),
			[n](int x) { return x>n; } );
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto& x : v)
		os << x << ", ";
	return os;
}

int main()
{
	list<Club> lc { {"club-a", "2011/02/11"}, {"club-b", "2013/12/10"}};
	f(lc, cout);
	cout << endl;

	vector<int> vi {1, 2, 3, 4, 5}, vo(5);
	f(vi, vo);
	cout << "vo: " << vo << endl;

	list<int> ld { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	f2(ld, 4, cout);
	cout << endl;
}
