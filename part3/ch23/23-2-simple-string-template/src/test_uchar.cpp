/*
 * test_wchar.cpp
 *
 *  Created on: 2016/09/08
 *      Author: sasaki
 */


#include "String.h"
#include <map>
#include <iostream>
using namespace std;

typedef unsigned char uchar;

void test_for_uchar()
{
	map<String<uchar>, int> m;
	for (String<uchar> buf; cin>>buf; )
		++m[buf];

	for (auto& x : m)
		cout << x.first << ": " << x.second << '\n';
}


