/*
 * regex.cpp
 *
 *  Created on: 2016/12/21
 *      Author: sasaki
 */


#include <regex>
#include <fstream>
#include <iostream>
using namespace std;

void use()
{
	ifstream in("file.txt");
	if (!in) cerr << "no file\n";

	regex pat {R"(\w{2}\s*\d{5}(-\d{4})?)"};

	int lineno = 0;
	for (string line; getline(in,line);) {
		++lineno;
		smatch matches;
		if (regex_search(line, matches, pat)) {
			cout << lineno << ": " << matches[0] << '\n';
			if (1<matches.size() && matches[1].matched)
				cout << "\t: " << matches[1] << '\n';
		}
	}
}

int main()
{
	use();
}
