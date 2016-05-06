/*
 * main_initializer_list.cpp
 *
 *  Created on: 2016/05/07
 *      Author: sasaki
 */

#include <string>
#include <initializer_list>
using namespace std;

extern void error(int severity, initializer_list<string> err);

int main(int argc, char* argv[])
{
	switch (argc) {
	case 1:
		error(0, {argv[0]});
		break;
	case 2:
		error(0, {argv[0], argv[1]});
		break;
	default:
		error(1, {argv[0], "with", to_string(argc-1), "arguments"});
	}
}

