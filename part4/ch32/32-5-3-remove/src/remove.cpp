/*
 * remove.cpp
 *
 *  Created on: 2016/11/30
 *      Author: sasaki
 */


#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

int main()
{
	string s {"*CamelCase*IsUgly*"};
	cout << s << '\n';
	auto p = remove(s.begin(), s.end(), '*');
	copy(s.begin(), p, ostream_iterator<char>{cout});
	cout << '\n';
	cout << s << '\n';
}
