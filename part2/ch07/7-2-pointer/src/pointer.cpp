/*
 * pointer.cpp
 *
 *  Created on: 2016/04/13
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

char c = 'a';
char* p = &c;
char c2 = *p;

int* pi;
char** ppc;
int* ap[15];
int (*fp)(char*);
int* f(char*);

int main()
{
	cout << "c = " << c << '\n';
	//cout << "p = " << p << '\n';
	cout << "c2 = " << c2 << '\n';
}



