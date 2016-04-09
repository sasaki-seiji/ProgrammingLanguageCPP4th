/*
 * main.cpp
 *
 *  Created on: 2016/03/28
 *      Author: sasaki
 */

#include <string>
#include <iostream>
#include <list>
#include "Less_than.h"
#include "count.h"
#include "Vector.h"

using namespace std;

Less_than<int> lti {42};
Less_than<string> lts {"Backus"};

void fct(int n, const string& s)
{
	bool b1 = lti(n);
	bool b2 = lts(s);

	cout << "lti(" << n << ") returns " << b1 << '\n';
	cout << "lts(" << s << ") returns " << b2 << '\n';
}

void f(const Vector<int>& vec, const list<string> lst, int x, const string& s)
{
	cout << "number of values less than " << x
			<< ": " << count(vec, Less_than<int>{x})
			<< '\n';
	cout << "number of values less than " << s
			<< ": " << count(lst, Less_than<string>{s})
			<< '\n';
}

void f2(const Vector<int>& vec, const list<string> lst, int x, const string& s)
{
	cout << "number of values less than " << x
			<< ": " << count(vec, [&](int a) { return a < x; })
			<< '\n';
	cout << "number of values less than " << s
			<< ": " << count(lst, [&](const string& a) { return a < s; })
			<< '\n';
}

int main()
{
	fct(10, "Becker");
	fct(100, "Auto");

	Vector<int>	vi(5);	// element is not initialized to zero
	vi[1] = 42; vi[3] = 32 ; vi[4] = 54;

	list<string> ls;
	ls.push_back("abc"); ls.push_back("xyz"); ls.push_back("char");

	f(vi, ls, 42, "string");
	f2(vi, ls, 42, "string");
}
