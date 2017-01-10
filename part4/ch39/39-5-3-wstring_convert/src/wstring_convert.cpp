/*
 * wstring_convert.cpp
 *
 *  Created on: 2017/01/10
 *      Author: sasaki
 */


#include <locale>
#include <codecvt>
#include <iostream>
#include <string>
using namespace std;

void f()
{
	wstring_convert<codecvt_utf8<wchar_t>> myconv;
	string s = myconv.to_bytes(L"Hello\n");
	cout << s;

	string s2 = myconv.to_bytes(L"こんにちは\n");
	cout << s2;
}

void test()
{
	wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	//wstring_convert<codecvt_utf8<wchar_t>> converter;

	string s8 = u8"This is a UTF-8 string";
	wstring s16 = converter.from_bytes(s8);
	string s88 = converter.to_bytes(s16);

	if (s8!=s88)
		cerr << "Insane!\n";

	cout << "s8:" << s8 << endl;
	cout << "s88:" << s88 << endl;
}

int main()
{
	f();
	test();
}
