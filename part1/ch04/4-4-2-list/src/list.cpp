/*
 * list.cpp
 *
 *  Created on: 2016/04/02
 *      Author: sasaki
 */

#include <list>
#include <iostream>
using namespace std;

#include "Entry.h"

list<Entry> phone_book = {
	{"David Hume", 123456},
	{"Karl Popper", 234567},
	{"Bertrand Arthur William Russell", 345678}
};

int get_number(const string& s)
{
	for (const auto& x : phone_book)
		if (x.name==s)
			return x.number;
	return 0;
}

int get_number2(const string& s)
{
	for (auto p = phone_book.begin(); p != phone_book.end(); ++p)
		if (p->name==s)
			return p->number;
	return 0;
}

void f(const Entry&& ee, list<Entry>::iterator p, list<Entry>::iterator q)
{
	phone_book.insert(p, ee);
	phone_book.erase(q);
}

// 2016.04.02 add
template<typename C>
void print_book(const C& book)
{
	for (const auto& x : book)
		cout << x << '\n';
}

int main()
{
	int x;

	x = get_number("Karl Popper");
	cout << "get_number(\"Karl Popper\") returns " << x << '\n';

	x = get_number2("Karl Popper");
	cout << "get_number2(\"Karl Popper\") returns " << x << '\n';

	cout << "print_book(phone_book):\n";
	print_book(phone_book);

	f(Entry{"inserted name", 11111111}, phone_book.end(), ++phone_book.begin());

	cout << "after f() call, print_book(phone_book):\n";
	print_book(phone_book);

}
