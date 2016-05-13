/*
 * resource_management.cpp
 *
 *  Created on: 2016/05/14
 *      Author: sasaki
 */

#include <cstdio>
#include <stdexcept>
#include <iostream>
#include "Fileptr.h"
using namespace std;


void use_file(const char* fn)
{
	FILE* f = fopen(fn, "r");
	if (!f) {
		fprintf(stderr, "can't open file: %s\n", fn);
		return;
	}
	try {
		throw runtime_error("error occurs in use_file()");
	}
	catch (...) {
		fclose(f);
		throw;
	}
	fclose(f);
}

void use_file2(const char* fn)
{
	File_ptr f(fn, "r");
	throw runtime_error("error occurs in use_file2()");
}

int main()
{
	try {
		use_file("test.txt");
	}
	catch (runtime_error& e) {
		cerr << e.what() << '\n';
	}

	try {
		use_file2("test.txt");
	}
	catch (runtime_error& e) {
		cerr << e.what() << '\n';
	}
}
