/*
 * match_results.cpp
 *
 *  Created on: 2016/12/21
 *      Author: sasaki
 */


#include <regex>
#include <iostream>
using namespace std;


void sub_match_equality()
{
	regex pat ("<(.*?)>(.*?)</(.*?)>");

	string s = "Always look on the <b> bright </b> side of <d> death </b>";

	smatch m;
	if (regex_search(s,m,pat))
		if (m[1]==m[3]) cout << "match\n";
}

void test()
{
	regex pat ("(AAAA)(BBB)?");
	string s = "AAAA";
	smatch m;
	regex_search(s,m,pat);

	cout << boolalpha;
	cout << m[0].matched << '\n';
	cout << m[1].matched << '\n';
	cout << m[2].matched << '\n';
	cout << m[3].matched << '\n';
}

int main()
{
	sub_match_equality();
	test();
}
