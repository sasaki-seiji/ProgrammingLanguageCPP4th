/*
 * Assoc.cpp
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */

#include "Assoc.h"
#include <utility>
using namespace std;

int& Assoc::operator[](const string& s)
{
	//for (auto x : vec)
	for (auto& x : vec)
		// warning: reference to local variable 'x' returned [-Wreturn-local-addr]
		if (s == x.first) return x.second;

	vec.push_back({s,0});
	return vec.back().second;
}

const int& Assoc::operator[](const string& s) const
{
	for (auto& x : vec)
		if (s == x.first) return x.second;

	throw Bad_index{};
}
