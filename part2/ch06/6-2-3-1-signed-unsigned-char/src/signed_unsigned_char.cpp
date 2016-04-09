/*
 * signed_unsigned_char.cpp
 *
 *  Created on: 2016/04/09
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

char c = 255;
int i = c;

void f(char c, signed char sc, unsigned char uc)
{
	//char* pc = &uc;
		// invalid conversion from 'unsigned char*' to 'char*' [-fpermissive]
	//signed char* psc = pc;
		// invalid conversion from 'char*' to 'signed char*' [-fpermissive]
	//unsigned char* puc = pc;
		// invalid conversion from 'char*' to 'unsigned char*' [-fpermissive]
	//psc = puc;
		// invalid conversion from 'unsigned char*' to 'signed char*' [-fpermissive]
}

void g(char c, signed char sc, unsigned char uc)
{
	c = 255;
	c = sc;
	c = uc;
	sc = uc;
	uc = sc;
	sc = c;
	uc = c;

	cout << "c = " << c << ", sc = " << sc << ", uc = " << uc << '\n';
}

int main()
{
	cout << "c = " << c << ", i = " << i << '\n';

	g('a', 'b', 'c');
	g('a', -100, 128);
}
