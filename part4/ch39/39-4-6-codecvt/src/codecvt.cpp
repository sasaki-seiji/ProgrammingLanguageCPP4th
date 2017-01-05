/*
 * codecvt.cpp
 *
 *  Created on: 2017/01/05
 *      Author: sasaki
 */

#include <iostream>
#include "Cvt_to_upper.h"
using namespace std;

int main()
{
	locale ulocale(locale("C"), new Cvt_to_upper);
	cerr << ulocale.name() << endl;

	cin.imbue(ulocale);
	for (char ch; cin>>ch; )
		cout << ch;
}

