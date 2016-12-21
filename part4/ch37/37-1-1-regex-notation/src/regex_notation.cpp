/*
 * regex_notation.cpp
 *
 *  Created on: 2016/12/21
 *      Author: sasaki
 */


#include <regex>
#include <iostream>
using namespace std;

bool is_identifier(const string& s)
{
	regex pat {"[_[:alpha:]]\\w*"};
	return regex_match(s,pat);
}

bool is_identifier2(const string& s)
{
	regex pat {R"([_[:alpha:]]\w*)"};
	return regex_match(s,pat);
}

void parse_xml(const string& s)
{
	smatch matches;
	regex pat {R"(<(.*?)>(.*?)</\1>)"};
	if (regex_search(s,matches,pat)) {
		cout << "tag: " << matches[1] << ", contents: " << matches[2] << endl;
	}
}

int main()
{
	string iden = "_cpp_identifier_sample";
	cout << is_identifier(iden) << endl;
	cout << is_identifier2(iden) << endl;

	string xml = "Always look on the <b>bright</b> side of <b>life</b>";
	parse_xml(xml);
}
