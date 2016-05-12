/*
 * error_initializer_list.cpp
 *
 *  Created on: 2016/05/07
 *      Author: sasaki
 */

#include <string>
#include <initializer_list>
#include <iostream>
using namespace std;

void error(int severity, initializer_list<string> err)
{
	for (auto& s : err)
		cerr << s << ' ';
	cerr << '\n';
	if (severity) exit(severity);
}


