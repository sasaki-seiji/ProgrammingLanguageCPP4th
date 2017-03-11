/*
 * multiple_resources.cpp
 *
 *  Created on: 2017/03/12
 *      Author: sasaki
 */

#include <iostream>
#include "Locked_file.h"

using namespace std;

void read_write(Locked_file_handle& f)
{
	cout << "-- read_print(Locked_file_handle) --\n";

	char buf[128];
	while (fgets(buf, 128, f))
		cout << buf;
}

void use(const char* fn, mutex& m)
{
	cout << "-- use(\"" << fn << "\") --\n";

	Locked_file_handle f(fn, m);

	read_write(f);
}

int main()
{
	mutex m;
	try {
		use("test.txt", m);
	}
	catch (const runtime_error& e) {
		cout << e.what() << endl;
	}
	m.lock();
	m.unlock();

	try {
		use("unknown.txt", m);
	}
	catch (const runtime_error& e) {
		cout << e.what() << endl;
	}
	m.lock();
	m.unlock();
}

