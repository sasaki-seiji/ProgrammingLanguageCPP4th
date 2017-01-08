/*
 * locale_comparison.cpp
 *
 *  Created on: 2017/01/08
 *      Author: sasaki
 */

#include <locale>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void user(const string s1, const string s2, const locale& my_locale)
{
	if (my_locale(s1,s2)) {
		cout << "s1 is less than s2\n";
	}
	else {
		cout << "s1 is not less than s2\n";
	}
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto x : v)
		os << x << ',';

	return os;
}

void f(vector<string>& v, const locale& my_locale)
{
	cout << v << endl;
	sort(v.begin(), v.end());
	cout << v << endl;
	sort(v.begin(), v.end(), my_locale);
	cout << v << endl;
}

int main()
{
	string s1 = "abcd";
	string s2 = "XYZ";

	cout << "glocal locale: ";
	user(s1,s2,locale{});

	cout << "en_US.UTF-8: ";
	user(s1,s2,locale{"en_US.UTF-8"});

	vector<string> v {"abc", "0123", "XYZ", "$%&" };
	f(v, locale{"en_US.UTF-8"});
}

