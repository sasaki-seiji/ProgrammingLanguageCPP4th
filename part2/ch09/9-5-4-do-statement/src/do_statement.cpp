/*
 * do_statement.cpp
 *
 *  Created on: 2016/04/24
 *      Author: sasaki
 */

#include <iostream>
#include <cstring>
using namespace std;

void print_backwards(char a[], int i)
{
	cout << '{';
	do {
		cout << a[--i];
	} while (i);
	cout << '}';
}

int main()
{
	char s1[] = "this is a string";
	print_backwards(s1, strlen(s1));

	char s2[] = "";
	print_backwards(s2, strlen(s2));
		// crash!!!
		// on Ubuntu terminated with exit value:-1
}

