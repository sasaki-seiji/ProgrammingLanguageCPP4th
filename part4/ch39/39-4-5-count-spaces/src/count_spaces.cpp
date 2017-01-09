/*
 * count_spaces.cpp
 *
 *  Created on: 2017/01/04
 *      Author: sasaki
 */


#include <locale>
#include <iostream>
using namespace std;

int count_spaces(const string& s, const locale& loc)
{
	const ctype<char>& ct = use_facet<ctype<char>>(loc);
	int i = 0;

	for(auto p = s.begin(); p!=s.end(); ++p)
		if (ct.is(ctype_base::space,*p))
			++i;
	return i;
}

int count_spaces_puncts(const string& s, const locale& loc)
{
	const ctype<char>& ct = use_facet<ctype<char>>(loc);
	int i = 0;

	for(auto p = s.begin(); p!=s.end(); ++p)
		if (ct.is(ctype_base::space|ctype_base::punct,*p))
			++i;
	return i;
}

const char* test_scan_is(const string& s, const locale& loc)
{
	const ctype<char>& ct = use_facet<ctype<char>>(loc);
	return ct.scan_is(ctype_base::punct, s.data(), s.data()+s.size());
}

void test_toupper(char* from, char* to, const locale& loc)
{
	const ctype<char>& ct = use_facet<ctype<char>>(loc);
	ct.toupper(from, to);
}

int main()
{
	string s = "abc def\tghi$jkl#\nmno\fpqr";
	locale loc1{};

	int i1 = count_spaces(s, loc1);
	cout << "i1: " << i1 << endl;

	int i2 = count_spaces_puncts(s, loc1);
	cout << "i2: " << i2 << endl;

	const char* p1 = test_scan_is(s, loc1);
	cout << "*p1: " << *p1 << endl;

	char chrs[] = "abc DEF\tghi$JKL#\tmno?pqr";
	test_toupper(begin(chrs), end(chrs)-1, loc1);
	cout << "after toupper(), chrs: " << chrs << endl;
}
