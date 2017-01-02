/*
 * named_locale.cpp
 *
 *  Created on: 2017/01/02
 *      Author: sasaki
 */

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	locale loc1;
	cout << "loc1: " << loc1.name() << '\n';
	locale loc2 {""};
	cout << "loc2: " << loc2.name() << '\n';
	locale loc3 {"C"};
	cout << "loc3: " << loc3.name() << '\n';
	locale loc4 {locale::classic()};
	cout << "loc4: " << loc4.name() << '\n';
	locale loc5 {"POSIX"};
	cout << "loc5: " << loc5.name() << '\n';
	try {
		locale loc6 {"Danish_Denmark.1252"};
		cout << "loc6: " << loc6.name() << '\n';
	}
	catch (const runtime_error& e) {
		cerr << "locale(\"Danish_Denmark.1252\"): " << e.what() << endl;
	}
	locale loc7 {"en_US.UTF-8"};
	cout << "loc7: " << loc7.name() << '\n';
}


