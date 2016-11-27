/*
 * count.cpp
 *
 *  Created on: 2016/11/27
 *      Author: sasaki
 */


#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>
using namespace std;

void f(const string& s)
{
	auto n_space = count(s.begin(),s.end(),' ');
	//auto n_whitespace = count_if(s.begin(),s.end(),isspace);
		// error: no matching function for call to 'count_if(std::__cxx11::basic_string<char>::const_iterator, std::__cxx11::basic_string<char>::const_iterator, <unresolved overloaded function type>)'
	auto n_whitespace = count_if(s.begin(),s.end(),(int(*)(int))isspace);

	cout << "n_space: " << n_space << endl;
	cout << "n_whitespace: " << n_whitespace << endl;
}

int main()
{
	string s = "this is a string with white space such as \t\n\v\f";
	f(s);
}
