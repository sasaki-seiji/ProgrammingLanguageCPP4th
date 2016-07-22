/*
 * constructor_and_destructor.cpp
 *
 *  Created on: 2016/07/22
 *      Author: sasaki
 */

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

template<typename Target =string, typename Source =string>
Target to(Source arg)
{
	stringstream interpreter;
	Target result;

	if (!(interpreter << arg)
		|| !(interpreter >> result)
		|| !(interpreter >> std::ws).eof())
		throw runtime_error{"to<>() failed"};

	return result;
}

struct Tracer {
	string mess;
	Tracer(const string& s) :mess{s} { clog << mess; }
	~Tracer() { clog << "~" << mess; }
};

void f(const vector<int>& v)
{
	Tracer tr {"in f()\n"};
	for (auto x : v) {
		Tracer tr {string{"v loop "} + to<string>(x) + '\n'};
		// ...
	}
}

int main()
{
	f({2,3,5});
}
