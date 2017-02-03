/*
 * range_check.cpp
 *
 *  Created on: 2016/04/02
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

#include "Entry.h"
#include "Vec.h"

void silly(vector<Entry>& book)
{
	int i = book[book.size()].number;

	cout << "book[book.size()].number returns " << i << '\n';
}

void checked(Vec<Entry>& book)
{
	try {
		book[book.size()] = {"Joe", 9999999};
	}
	catch (out_of_range) { // Catching by reference is recommended 'out_of_range'
		cout << "range error\n";
	}
}

vector<Entry> phone_book = {
	{"David Hume", 123456},
	{"Karl Popper", 234567},
	{"Bertrand Arthur William Russell", 345678}
};

Vec<Entry> phone_book2 = {
	{"David Hume", 123456},
	{"Karl Popper", 234567},
	{"Bertrand Arthur William Russell", 345678}
};

int main()
try {
	silly(phone_book);
	checked(phone_book2);
}
catch (out_of_range)
{
	cerr << "range error\n";
}
catch (...)
{
	cerr << "unknow exception thrown\n";
}
