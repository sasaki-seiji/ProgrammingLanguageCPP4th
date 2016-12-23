/*
 * regex_token_iterator.cpp
 *
 *  Created on: 2016/12/23
 *      Author: sasaki
 */


#include <regex>
#include <iostream>
using namespace std;

void test1()
{
	cout << "-- test1() --\n";

	string input {"aa::bb cc::dd ee::ff"};
	regex pat {R"((\w+)([[:punct:]]+)(\w+)\s*)"};
	sregex_token_iterator end{};
	for (sregex_token_iterator p{input.begin(),input.end(),pat,{1,3}}; p!=end; ++p)
		cout << *p << '\n';
}

void test2()
{
	cout << "-- test2() --\n";

	string s {"1,2 , 3 ,4,5, 6 7"};
	regex pat {R"(\s*,\s*)"};
	copy(sregex_token_iterator{s.begin(),s.end(),pat,-1},
			sregex_token_iterator{},
			ostream_iterator<string>(cout,"\n"));
}

void test3()
{
	cout << "-- test3() --\n";

	string s {"1,2 , 3 ,4,5, 6 7"};
	regex pat {R"(\s*,\s*)"};

	sregex_token_iterator end{};
	for (sregex_token_iterator p {s.begin(),s.end(),pat,-1}; p!=end; ++p)
		cout << *p << '\n';
}

int main()
{
	test1();
	test2();
	test3();
}
