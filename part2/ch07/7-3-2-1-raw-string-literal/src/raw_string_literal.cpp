/*
 * raw_string_literal.cpp
 *
 *  Created on: 2016/04/14
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

string s = "\\w+\\\\\\w+";
string rs = R"(\w+\\\w+)";

string counts {R"(1
22
333)"};

int main()
{
	cout << "s = " << s << '\n';
	cout << "rs = " << rs << '\n';
	cout << R"("quoted string")" << '\n';
	cout << R"***("quoted string containing the usal terminator ("))")***" << '\n';
	cout << "counts = " << counts << '\n';
}

