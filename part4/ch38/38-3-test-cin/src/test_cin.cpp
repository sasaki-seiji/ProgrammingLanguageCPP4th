/*
 * test_cin.cpp
 *
 *  Created on: 2016/12/25
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

void try_read_int()
{
	int i;
	if (cin>>i) {
		cout << "read int: " << i << endl;
	}
	else if (cin.fail()) {
		cin.clear();
		string s;
		if (cin>>s) {
			cout << "read string: \"" << s << "\"" << endl;
		}
	}
}

void read_ints()
{
	for (int x; cin>>x;) {
		cout << "x: " << x << endl;
	}
}

int main()
{
	try_read_int();
	read_ints();
}
