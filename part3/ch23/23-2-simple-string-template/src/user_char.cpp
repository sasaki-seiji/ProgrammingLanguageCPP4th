/*
 * user_char.cpp
 *
 *  Created on: 2016/09/08
 *      Author: sasaki
 */


#include "String.h"
#include <map>
#include <iostream>
using namespace std;

void test_19_3_6_for_char()
{
	cout << "-- total test for String<char>\n" << flush;

	String<char> s ("abcdefghij");
	cout << s << '\n';
	s += 'k';
	s += 'l';
	s += 'm';
	s += 'n';
	cout << s << '\n';

	String<char> s2 = "Hell";
	s2 += " and high water";
	cout << s2 << '\n';

	String<char> s3 = "qwerty";
	s3 = s3;
	String<char> s4 = "the quick brown fox jumped over the lazy dog";
	s4 = s4;
	cout << s3 << " " << s4 << "\n";
	cout << s + ". " + s3 + String<char>(". ") + "Horsefeathers\n";

	cout << flush ;
	cout << "enter string : quit for end\n" << flush;
	String<char> buf;
	while (cin>>buf && buf!="quit")
		cout << buf << " " << buf.size() << " " << buf.capacity() << '\n' << flush;
}

void word_count()
{
	cout << "-- word count for String<char>\n" << flush;

	map<String<char>, int> m;
	for (String<char> buf; cin>>buf; )
		++m[buf];

	for (auto& x : m)
		cout << x.first << ": " << x.second << '\n';
}

