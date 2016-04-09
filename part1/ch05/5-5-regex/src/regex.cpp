/*
 * regex.cpp
 *
 *  Created on: 2016/04/07
 *      Author: sasaki
 */

#include <regex>
#include <iostream>
using namespace std;

int main()
{
	regex pat (R"(\w{2}\s*\d{5}(-\d{4})?)");

	int lineno = 0;
	for (string line; getline(cin, line); ) {
		++lineno;
		smatch matches;
		if (regex_search(line, matches, pat))
			cout << lineno << ": " << matches[0] << '\n';
	}
}


