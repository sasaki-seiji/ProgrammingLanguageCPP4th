/*
 * meney_get.cpp
 *
 *  Created on: 2017/01/04
 *      Author: sasaki
 */


#include "Money.h"
using namespace std;

int main()
{
	locale myloc {locale(), new My_money_io};
	cin.imbue(myloc);
	cout.imbue(myloc);

	Money m;
	while (cin>>m)
		cout << m << "\n";
}

