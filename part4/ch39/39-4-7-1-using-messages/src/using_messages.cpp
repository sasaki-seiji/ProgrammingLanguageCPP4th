/*
 * using_messages.cpp
 *
 *  Created on: 2017/01/10
 *      Author: sasaki
 */


#include <iostream>
#include "My_messages.h"
#include "Season.h"
using namespace std;

string message_directory = "messages/";

int main()
{
	Season x;

	cin >> x;
	cout << x << endl;

	locale glob(locale(), new My_messages);
	locale::global(glob);	// used in Season_io facet

	locale loc(locale(), new Season_io{});
	cout.imbue(loc);
	cin.imbue(loc);

	cin >> x;
	cout << x << endl;
}



