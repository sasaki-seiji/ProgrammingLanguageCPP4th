/*
 * mutating_sequence_algorithm.cpp
 *
 *  Created on: 2016/11/29
 *      Author: sasaki
 */

#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

template<typename In, typename Out, typename Op>
Out my_transform(In first, In last, Out res, Op op)
{
	while (first!=last)
		*res++ = op(*first++);
	return res;
}

void toupper(string& s)
{
	//transform(s.begin(),s.end(),s.begin(),toupper);
	transform(s.begin(),s.end(),s.begin(),(int(*)(int))toupper);
		// error: no matching function for call to 'transform(std::__cxx11::basic_string<char>::iterator, std::__cxx11::basic_string<char>::iterator, std::__cxx11::basic_string<char>::iterator, <unresolved overloaded function type>)'
}

void my_toupper(string& s)
{
	my_transform(s.begin(),s.end(),s.begin(),(int(*)(int))toupper);
}

int main()
{
	string s { "this is a string" };
	toupper(s);
	cout << "toupper(s); s: " << s << endl;

	string s2 { "this is another string" };
	my_toupper(s2);
	cout << "my_toupper(s2); s2: " << s2 << endl;
}
