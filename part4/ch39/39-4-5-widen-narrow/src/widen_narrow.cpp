/*
 * widen_narrow.cpp
 *
 *  Created on: 2017/01/04
 *      Author: sasaki
 */

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	//wcout.imbue(locale("ja_JP.UTF-8"));
	wcout.imbue(locale(""));

	wcout << use_facet<ctype<wchar_t>>(wcout.getloc()).widen('e') << endl;
	wchar_t wc = L'Ｅ';
	wcout << hex << int{wc} << endl;
	wcout << use_facet<ctype<wchar_t>>(wcout.getloc()).narrow(wc,'a') << endl;
}

