/*
 * codecvt.cpp
 *
 *  Created on: 2017/01/05
 *      Author: sasaki
 */

#include <iostream>
#include <fstream>
#include "Cvt_to_upper.h"
using namespace std;

int main()
{
	locale ulocale(locale("C"), new Cvt_to_upper);

	cin.imbue(ulocale);
	for (char ch; cin>>ch; )
		cout << ch;

	ifstream ifs("test.txt");
	ifs.imbue(ulocale);
	for (char ch; ifs>>ch; )
		cout << ch;
}

