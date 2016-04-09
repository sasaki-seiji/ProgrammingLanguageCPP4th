/*
 * phone_book.cpp
 *
 *  Created on: 2016/04/02
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
#include "Entry.h"
#include "shape.h"
using namespace std;

vector<Entry> phone_book = {
	{"David Hume", 123456},
	{"Karl Popper", 234567},
	{"Bertrand Arthur William Russell", 345678}
};

void print_book(const vector<Entry>& book)
{
	for (int i = 0; i != book.size(); ++i) // comparison between signed and unsigned integer expressions [-Wsign-compare]
		cout << book[i] << '\n';
}

void print_book2(const vector<Entry>& book)
{
	for (const auto& x : book)
		cout << x << '\n';
}

vector<int> v1 = {1, 2, 3, 4};
vector<string> v2;
vector<Shape*> v3(23);
vector<double> v4(32, 9.9);

void input()
{
	for (Entry e; cin>>e; )
		phone_book.push_back(e);
}

int main()
{
	cout << "print_book(phone_book)\n";
	print_book(phone_book);

	cout << "print_book2(phone_book)\n";
	print_book2(phone_book);

	cout << "calling input()\n";
	input();

	cout << "call again print_book2(phone_book)\n";
	print_book2(phone_book);

	vector<Entry> book2 = phone_book;
	cout << "after book2 = phone_bock, print_book2(book2)\n";
	print_book2(book2);
}
