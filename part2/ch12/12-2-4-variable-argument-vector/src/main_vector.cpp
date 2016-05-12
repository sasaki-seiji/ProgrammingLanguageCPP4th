/*
 * main_vector.cpp
 *
 *  Created on: 2016/05/07
 *      Author: sasaki
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

void error(int severity, const vector<string>& err)
{
	for (auto& s : err)
		cerr << s << ' ';
	cerr << '\n';
	if (severity) exit(severity);
}

vector<string> arguments(int argc, char* argv[])
{
	vector<string> res;
	for (int i = 0; i < argc; ++i)
		res.push_back(argv[i]);
	return res;
}

int main(int argc, char* argv[])
{
	auto args = arguments(argc, argv);
	error((args.size()<=2)?0:1, args);
}
