/*
 * main.cpp
 *
 *  Created on: 2016/07/28
 *      Author: sasaki
 */


#include "Club.h"
#include <iostream>
using namespace std;

struct B { B(int); };
struct BB : B { };
struct BBB : BB {
	//BBB(int i) : B(i) { }
		// error: type 'B' is not a direct base of 'BBB'
};

int main()
{
	Club club {"club-name", Date{ 25, 12, 1959 } };
	club.print(cout);
}
