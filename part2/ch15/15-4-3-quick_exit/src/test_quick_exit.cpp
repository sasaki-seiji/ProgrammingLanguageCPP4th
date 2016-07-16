/*
 * test_quick_exit.cpp
 *
 *  Created on: 2016/07/15
 *      Author: sasaki
 */


#include <cstdlib>
#include <iostream>
using namespace std;

void my_cleanup();

void somewhere()
{
	if (at_quick_exit(&my_cleanup) == 0) {
		cout << "succeed at_quick_exit()\n";
	}
	else {
		cout << "fail at_quick_exit()\n";
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
	quick_exit(0);
}


