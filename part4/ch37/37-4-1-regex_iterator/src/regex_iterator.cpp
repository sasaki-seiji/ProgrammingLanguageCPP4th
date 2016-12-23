/*
 * regex_iterator.cpp
 *
 *  Created on: 2016/12/23
 *      Author: sasaki
 */

#include <regex>
#include <iostream>
using namespace std;

void test()
{
	string input = "as as; asd ++e^asdf asdfg";

	string str {R"(\s+(\w+))"};
	regex pat {str};
	cout << "-- pattern: " << str << endl;
	for (sregex_iterator p(input.begin(),input.end(),pat); p!=sregex_iterator{}; ++p)
		cout << (*p)[1] << '\n';

	string str2 {R"((\w+))"};
	regex pat2 {str2};
	cout << "-- pattern: " << str2 << endl;
	for (sregex_iterator p(input.begin(),input.end(),pat2); p!=sregex_iterator{}; ++p)
		cout << (*p)[1] << '\n';

}

int main()
{
	test();
}
