/*
 * user_wchar_t.cpp
 *
 *  Created on: 2016/09/09
 *      Author: sasaki
 */

#include "String.h"
#include <iostream>
using namespace std;

void test_19_3_6_for_wchar_t()
{
	cout << "-- test_19_3_6_for_wchar_t\n" << flush ;

	String<wchar_t> s (L"abcdefghij");
	cout << s << '\n';
	s += L'k';
	s += L'l';
	s += L'm';
	s += L'n';
	cout << s << '\n';

	String<wchar_t> s2 = L"Hell";
	s2 += L" and high water";
	cout << s2 << '\n';

	String<wchar_t> s3 = L"qwerty";
	s3 = s3;
	String<wchar_t> s4 = L"the quick grown fox jumped over the lazy dog";
	s4 = s4;
	cout << s3 << " " << s4 << "\n";
	cout << s + L". " + s3 + String<wchar_t>(L". ") + L"Horsefeathers\n";

#if 0
	String<wchar_t> buf;
	while (cin>>buf && buf!=L"quit")
		cout << buf << " " << buf.size() << " " << buf.capacity() << '\n';
#endif
}


