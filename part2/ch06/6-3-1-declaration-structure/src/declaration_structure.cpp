/*
 * declaration_structure.cpp
 *
 *  Created on: 2017/02/10
 *      Author: sasaki
 */

#include <iostream>
#include <typeinfo>
using namespace std;

const char* kings[] = { "Antigonus", "Selencus", "Ptolemy" };

//const c = 7;
	// error: ‘c’ does not name a type

#if 0
// error: ISO C++ forbids declaration of ‘gt’ with no type [-fpermissive]
gt(int a, int b)
{
	return (a>b) ? a : b;
}
#endif


unsigned ui;
long li;

int main()
{
	cout << "typeid(kings) = " << typeid(kings).name() << endl;
	cout << "typeid(ui) = " << typeid(ui).name() << endl;
	cout << "typeid(li) = " << typeid(li).name() << endl;
}

