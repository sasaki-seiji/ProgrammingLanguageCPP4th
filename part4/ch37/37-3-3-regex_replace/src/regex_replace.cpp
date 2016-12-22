/*
 * regex_replace.cpp
 *
 *  Created on: 2016/12/23
 *      Author: sasaki
 */


#include <regex>
#include <string>
#include <iostream>
using namespace std;

void test1()
{
	string input {"x 1 y22 22 zaq 34567"};
	regex pat {R"((\w+)\s(\d+))"};
	string format {"{$1,$2}\n"};

	cout << regex_replace(input,pat,format);
	cout << regex_replace(input,pat,format,regex_constants::format_no_copy);
}

void test2()
{
	string input {"x 1 y22 22 zaq 34567"};
	regex pat {R"((\w+)\s(\d+))"};
	string format {"$2: $1\n"};

	cout << regex_replace(input,pat,format,regex_constants::format_no_copy);
}
int main()
{
	test1();
	test2();
}
