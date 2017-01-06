/*
 * main.cpp
 *
 *  Created on: 2017/01/06
 *      Author: sasaki
 */

#include <iostream>
#include "Season.h"
using namespace std;

int main()
{
	Season x;

	cin >> x;
	cout << x << endl;

	locale loc(locale(), new US_season_io{});
	cout.imbue(loc);
	cin.imbue(loc);

	cin >> x;
	cout << x << endl;
}

