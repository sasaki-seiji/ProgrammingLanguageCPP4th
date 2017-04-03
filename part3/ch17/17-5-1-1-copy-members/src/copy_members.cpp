/*
 * default_constructor.cpp
 *
 *  Created on: 2016/07/31
 *      Author: sasaki
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class X {
	string s;
	string s2;
	vector<string> v;

public:
	X(const X& a)
		:s{a.s}, v{a.v}
	{

	}

	X(const string& si, const string& si2, const vector<string>& vi)
		: s{si}, s2{si2}, v{vi}
	{
	}

	void print(ostream& os);
};

ostream& operator<<(ostream& os, const vector<string>& v)
{
	os << '[';
	for (auto& x : v)
		os << x << ',';
	os << ']';
	return os;
}

void X::print(ostream& os)
{
	os << "X:s{" << s << "},s2{" << s2 << "},v{" << v << "}\n";
}


class Y {
	string s;
	string s2;
	vector<string> v;

public:
	Y(const string& si, const string& si2, const vector<string>& vi)
		: s{si}, s2{si2}, v{vi}
	{
	}

	void print(ostream& os);
};

void Y::print(ostream& os)
{
	os << "Y:s{" << s << "},s2{" << s2 << "},v{" << v << "}\n";
}


// add main

int main()
{
	cout << "- miss coping a memeber s2 -\n";

	X x1{"aaa", "xyz", {"123", "abc", "ABC"}};
	x1.print(cout) ;

	X x2{x1};
	x2.print(cout);

	cout << "- use default copy constructor -\n";

	Y y1{"aaa", "xyz", {"123", "abc", "ABC"}};
	y1.print(cout) ;

	Y y2{y1};
	y2.print(cout);
}
