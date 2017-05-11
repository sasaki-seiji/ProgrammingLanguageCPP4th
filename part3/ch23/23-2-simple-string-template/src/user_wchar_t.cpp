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
	wcout << s << '\n';
	s += L'k';
	s += L'l';
	s += L'm';
	s += L'n';
	wcout << s << '\n';

	String<wchar_t> s2 = L"Hell";
	s2 += L" and high water";
	wcout << s2 << '\n';

	String<wchar_t> s3 = L"qwerty";
	s3 = s3;
	String<wchar_t> s4 = L"the quick grown fox jumped over the lazy dog";
	s4 = s4;
	wcout << s3 << " " << s4 << "\n";
	wcout << s + L". " + s3 + String<wchar_t>(L". ") + L"Horsefeathers\n";

#if 1
	wcout << L"enter string : quit for end\n";
	String<wchar_t> buf;
	while (wcin>>buf && buf!=L"quit")
		wcout << buf << L" " << buf.size() << L" " << buf.capacity() << L'\n';
#endif
}


