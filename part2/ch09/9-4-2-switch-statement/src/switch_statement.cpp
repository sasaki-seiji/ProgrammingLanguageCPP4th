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
		// error: could not convert '2.7000000000000002e+0' from 'double' to 'int'
		//break;
	case 2:
		break;
	//case 4-2:
		// error: duplicate case value
		//break;
	}
}

void f() { cout << "f() called\n"; }
void g() { cout << "g() called\n"; }
void h() { cout << "h() called\n"; }

void use_switch(int val)
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

void use_if_else(int val)
{
	if (val == 1)
		f();
	else if (val == 2)
		g();
	else
		h();
}

void fall_through(int val)
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
		// warning: enumeration value 'chalice' not handled in switch [-Wswitch]
	case Vessel::cup:		cout << "Vessel::cup\n"; break;
	case Vessel::glass:		cout << "Vessel::glass\n"; break;
	case Vessel::goblet:	cout << "Vessel::goblet\n"; break;
	}
}

int main()
{
	f(2);

	cout << "-- calling use_switch(1):\n"; use_switch(1);
	cout << "-- calling use_switch(3):\n"; use_switch(3);

	cout << "-- calling use_if_else(1):\n"; use_if_else(1);
	cout << "-- calling use_if_else(2):\n"; use_if_else(2);

	cout << "-- calling fall_through(1):\n"; fall_through(1);
	cout << "-- calling fall_through(3):\n"; fall_through(3);

	cout << "-- calling proglematic(Vessel::glass)\n"; problematic(Vessel::glass);
}

