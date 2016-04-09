/*
 * unordered_map.cpp
 *
 *  Created on: 2016/04/02
 *      Author: sasaki
 */

#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, int> phone_book = {
	{"David Hume", 123456},
	{"Karl Popper", 234567},
	{"Bertrand Arthur William Russell", 345678}
};

int get_number(const string& s)
{
	return phone_book[s];
}

int main()
{
	int x;

	x = get_number("Karl Popper");
	cout << "get_number(\"Karl Popper\") returns " << x << '\n';
}




