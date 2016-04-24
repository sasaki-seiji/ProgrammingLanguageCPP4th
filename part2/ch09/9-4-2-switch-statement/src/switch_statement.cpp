/*
 * switch_statement.cpp
 *
 *  Created on: 2016/04/23
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void f(int i)
{
	switch (i){
	//case 2.7:
		// could not convert '2.7000000000000002e+0' from 'double' to 'int'
		//break;
	case 2:
		break;
	//case 4-2:
		// duplicate case value
		//break;
	}
}

void f() { cout << "f() called\n"; }
void g() { cout << "g() called\n"; }
void h() { cout << "h() called\n"; }

void f2(int val)
{
	switch (val){
	case 1:
		f();
		break;
	case 2:
		g();
		break;
	case 3:
		h();
		break;
	}
}

void f3(int val)
{
	if (val == 1)
		f();
	else if (val == 2)
		g();
	else
		h();
}

void f4(int val)
{
	switch (val){
	case 1:
		cout << "case 1\n";
			// No break at the end of case
	case 2:
		cout << "case 2\n";
			// No break at the end of case
	default:
		cout << "default: case not found\n";
	}
}

enum class Vessel { cup, glass, goblet, chalice };
void problematic(Vessel v)
{
	switch (v){
		// enumeration value 'chalice' not handled in switch [-Wswitch]
	case Vessel::cup:		break;
	case Vessel::glass:		break;
	case Vessel::goblet:	break;
	}
}

int main()
{
	f(2);

	cout << "calling f2(1): "; f2(1);
	cout << "calling f2(3): "; f2(3);

	cout << "calling f3(1): "; f3(1);
	cout << "calling f3(3): "; f3(3);

	cout << "calling f4(1): "; f4(1);
	cout << "calling f4(3): "; f4(3);

	cout << "calling proglematic(Vessel::glass)\n"; problematic(Vessel::glass);
}

