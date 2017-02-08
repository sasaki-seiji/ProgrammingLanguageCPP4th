/*
 * char.cpp
 *
 *  Created on: 2016/04/09
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void inval()
{
	cout << "inval():\n";

	for (char c; cin >> c; )
		cout << "the value of '" << c << "' is " << int{c} << '\n';
}

void digits()
{
	cout << "digits():\n";

	for (int i=0; i!=10; ++i)
		cout << static_cast<char>('0'+i);
}

int main()
{
	inval();
	digits();
}
