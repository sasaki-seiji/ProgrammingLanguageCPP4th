/*
 * user_char.cpp
 *
 *  Created on: 2016/09/08
 *      Author: sasaki
 */


#include "String.h"
#include <map>
#include <iostream>
using namespace std;


void test_for_char()
{
	map<String<char>, int> m;
	for (String<char> buf; cin>>buf; )
		++m[buf];

	for (auto& x : m)
		cout << x.first << ": " << x.second << '\n';
}

