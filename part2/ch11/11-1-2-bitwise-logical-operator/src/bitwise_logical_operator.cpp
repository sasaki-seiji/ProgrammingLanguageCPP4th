/*
 * bitwise_logical_operator.cpp
 *
 *  Created on: 2016/04/29
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

constexpr unsigned short middle(int a)
{
	static_assert(sizeof(int)==4, "unexpeced int size");
	static_assert(sizeof(short)==2, "unexpected short size");
	return (a>>8)&0xFFFF;
}

int main()
{
	char	buf[80];

	int old = cin.rdstate();
	cin >> buf;
	if (cin.rdstate() != old) {
		cout << cin.rdstate() << '\n';
	}

	int x = 0xFF00FF00;
	short y = middle(x);

	cout << "y: " << y << '\n';
}

