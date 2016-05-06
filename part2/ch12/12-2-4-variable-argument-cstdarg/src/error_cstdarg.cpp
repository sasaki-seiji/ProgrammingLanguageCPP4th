/*
 * error_cstdarg.cpp
 *
 *  Created on: 2016/05/07
 *      Author: sasaki
 */

#include <cstdarg>
#include <iostream>
using namespace std;

void error(int severity ...)
{
	va_list ap;
	va_start(ap, severity);

	for (;;) {
		char* p = va_arg(ap, char*);
		if (p == nullptr) break;
		cerr << p << ' ';
	}

	va_end(ap);

	cerr << '\n';
	if (severity) exit(severity);
}


