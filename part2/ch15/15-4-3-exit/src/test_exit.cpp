/*
 * terminate_program.cpp
 *
 *  Created on: 2016/07/13
 *      Author: sasaki
 */

#include <cstdlib>
#include <iostream>
using namespace std;

void my_cleanup();

void somewhere()
{
	if (atexit(&my_cleanup) == 0) {
		cout << "succeed atexit()\n";
	}
	else {
		cout << "fail atexit()\n";
	}
}

// define undef-func
void my_cleanup()
{
	cout << "my_cleanup()\n";
}

class X
{
public:
	X(const char* mes) : message{mes}
	{ cout << "construct X(\"" << mes << "\")\n"; }

	~X()
	{ cout << "destruct X(\"" << message << "\")\n"; }

private:
	string message;
};

X global("global variable");

// add main
int main()
{
	X local("local variable");

	somewhere();
	exit(0);
}
