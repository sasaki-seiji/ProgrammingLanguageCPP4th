/*
 * regex_match.cpp
 *
 *  Created on: 2016/12/21
 *      Author: sasaki
 */


#include <regex>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream in("table.txt");
	if (!in) cerr << "no file\n";

	string line;
	int lineno = 0;

	regex header {R"(^[\w ]+(\t[\w ]+)*$)"};
	regex row {R"(^([\w ]+)(\t\d+)(\t\d+)(\t\d+)$)"};

	if (getline(in,line)) {
		smatch matches;
		if (!regex_match(line,matches,header))
			cerr << "no header\n";
	}

	int boys = 0;
	int girls = 0;

	while (getline(in,line)) {
		++lineno;
		smatch matches;

		if (!regex_match(line,matches,row))
			cerr << "bad line: " << lineno << '\n';

		int curr_boy = stoi(matches[2]);
		int curr_girl = stoi(matches[3]);
		int curr_total = stoi(matches[4]);
		if (curr_boy+curr_girl != curr_total) cerr << "bad row sum \n";

		if (matches[1]=="Total") {
			if (curr_boy != boys) cerr << "boys do not add up\n";
			else if (curr_girl != girls) cerr << "girils do no add up\n";
			else cout << "all is well\n";
			return 0;
		}
		boys += curr_boy;
		girls += curr_girl;
	}

	cerr << "didn't find total line\n";
	return 1;
}
