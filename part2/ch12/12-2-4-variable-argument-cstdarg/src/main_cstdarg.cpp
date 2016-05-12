/*
 * main_cstdarg.cpp
 *
 *  Created on: 2016/05/07
 *      Author: sasaki
 */

#include <cstdio>

extern void error(int ...);
extern char* itoa(int, char[]);

int main(int argc, char* argv[])
{
	switch (argc) {
	case 1:
		error(0, argv[0], nullptr);
		break;
	case 2:
		error(0, argv[0], argv[1], nullptr);
		break;
	default:
		char buffer[8];
		error(1, argv[0], "with", itoa(argc-1, buffer), "arguments", nullptr);
	}
}

char* itoa(int x, char buf[])
{
	sprintf(buf, "%d", x);
	return buf;
}
