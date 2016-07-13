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

// add main
int main()
{
	somewhere();
	exit(0);
}
