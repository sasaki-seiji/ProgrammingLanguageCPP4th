/*
 * user.cpp
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */


#include "Assoc.h"

#include <string>
#include <iostream>
using namespace std;

int main()
{
	Assoc values;
	string buf;
	while(cin>>buf) ++values[buf];
	for (auto x : values.vec)
		cout << '{' << x.first << ',' << x.second << "}\n";
}
