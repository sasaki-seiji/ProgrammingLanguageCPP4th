/*
 * match_results.cpp
 *
 *  Created on: 2016/12/21
 *      Author: sasaki
 */


#include <regex>
#include <iostream>
using namespace std;

int main()
{
	regex pat ("<(.*?)>(.*?)</(.*?)>");

	string s = "Always look on the <b> bright </b> side of <d> death </b>";

	smatch m;
	if (regex_search(s,m,pat))
		if (m[1]==m[3]) cout << "match\n";
}
