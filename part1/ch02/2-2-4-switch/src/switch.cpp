/*
 * switch.cpp
 *
 *  Created on: 2016/03/19
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

bool accept2()
{
	cout << "Do you want to proceed (y or n)?\n";

	char answer = 0;
	cin >> answer;

	switch(answer) {
	case 'y':
		return true;
	case 'n':
		return false;
	default:
		cout << "I'll take that for a no.\n";
		return false;
	}
}

int main()
{
	bool ans = accept2();
	cout << "accept2() returns " << ans << endl;
}
