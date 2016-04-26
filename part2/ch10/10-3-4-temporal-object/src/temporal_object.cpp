/*
 * temporal_object.cpp
 *
 *  Created on: 2016/04/26
 *      Author: sasaki
 */


#include <string>
#include <iostream>
#include <cstring>
using namespace std;

void f(string& s1, string& s2, string s3)
{
	const char* cs = (s1+s2).c_str();
	cout << cs; // use memory already freed
	if (8<strlen(cs=(s2+s3).c_str()) && cs[0] == 'a')
	{
		cout << cs; // use memory already freed
	}
	cout << '\n';
}

void f2(string& s1, string& s2, string& s3)
{
	cout << s1+s2;
	string s = s2+s3;
	if (8<s.length() && s[0] == 'a') {
		cout << s;
	}
	cout << '\n';
}

void g(const string& s1, const string& s2)
{
	cout << s1 << s2 << '\n';
}

void h(string& s1, string& s2)
{
	const string& s = s1+s2;
	string ss = s1+s2;
	g(s, ss);
}

void f(string& s, int n, char ch)
{
	//s.move(string{n,ch});
	//s = move(string{n,ch});
		// narrowing conversion of 'n' from 'int' to 'char' inside { } [-Wnarrowing]
	s = move(string(n,ch));
	cout << s << '\n';
}

int main()
{
	string s1 = "012345";
	string s2 = "abcde";
	string s3 = "XYZUVW";

	f(s1, s2, s3);
	f2(s1, s2, s3);
	h(s1, s2);
	f(s1, 5, 'x');
}
