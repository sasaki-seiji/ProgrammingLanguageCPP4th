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

bool fire_exception = false;

void read_print(FILE* fp)
{
	cout << "-- read_print(FILE*) --\n";

	if (fire_exception) {
		throw runtime_error("read_print() : read error");
	}

	char buf[128];
	while (fgets(buf, 128, fp))
		cout << buf;
}

void read_print(File_ptr& fp) // can't copy File_ptr
{
	cout << "-- read_print(File_ptr) --\n";

	if (fire_exception) {
		throw runtime_error("read_print() : read error");
	}

	char buf[128];
	while (fgets(buf, 128, fp))
		cout << buf;
}

void use_file(const char* fn)
{
	cout << "-- use_file(\"" << fn << "\") --\n";

	FILE* f = fopen(fn, "r");
	if (!f) throw runtime_error("use_file(): can't open file");

	try {
		read_print(f);
	}
	catch (...) {
		fclose(f);
		throw;
	}
	fclose(f);
}

void use_file2(const char* fn)
{
	cout << "-- use_file2(\"" << fn << "\") --\n";

	File_ptr f(fn, "r");
	read_print(f);
}

int main()
{
	try {
		fire_exception = false;
		use_file("test.txt");
		fire_exception = true;
		use_file("test.txt");
	}
	catch (runtime_error& e) {
		cout << e.what() << '\n';
	}

	try {
		fire_exception = false;
		use_file2("test.txt");
		fire_exception = true;
		use_file2("test.txt");
	}
	catch (runtime_error& e) {
		cout << e.what() << '\n';
	}
	catch (...) {
		cout << "unknown error\n";
	}
}
