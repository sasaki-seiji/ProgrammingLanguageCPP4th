/*
 * find.cpp
 *
 *  Created on: 2016/11/27
 *      Author: sasaki
 */


#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

void f(const string& s)
{
	auto p_space = find(s.begin(),s.end(),' ');
	auto p_whitespace = find_if(s.begin(),s.end(), (int(*)(int))isspace);

	if (p_space!=s.end())
		cout << "*p_space: '" << *p_space << "'"<< endl;
	if (p_whitespace!=s.end())
		cout << "*p_whitespace: '" << *p_whitespace << "'"<< endl;
}


array<int,3> x = {1,3,4};
array<int,5> y = {0,2,3,4,5};

void f()
{
	auto p = find_first_of(x.begin(), x.end(), y.begin(), y.end());
	auto q = find_first_of(p+1, x.end(), y.begin(), y.end());

	if (p!=x.end())
		cout << "x[" << p-&x[0] << "]: " << *p << endl;
	if (q!=x.end())
		cout << "x[" << q-&x[0] << "]: " << *q << endl;
}

int main()
{
	string s = "\n\tthis is a string with white space such as \t\n\v\f";
	f(s);
	f();
}
