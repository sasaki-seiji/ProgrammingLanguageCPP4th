/*
 * algorism.cpp
 *
 *  Created on: 2016/04/03
 *      Author: sasaki
 */

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

#include "Entry.h"

bool operator<(const Entry& x, const Entry& y)
{
	return x.name < y.name;
}

// 2016.04.03 add
bool operator==(const Entry& x, const Entry& y)
{
	return x.name == y.name ;
}

void f(vector<Entry>& vec, list<Entry>& lst)
{
	sort(vec.begin(), vec.end());
	unique_copy(vec.begin(), vec.end(), lst.begin());
}

list<Entry> f2(vector<Entry>& vec)
{
	list<Entry> res;
	sort(vec.begin(), vec.end());
	unique_copy(vec.begin(), vec.end(), back_inserter(res));
	return res;
}

vector<Entry> phone_book_vec = {
	{"David Hume", 123456},
	{"Sasaki Seiji", 7525790},
	{"Karl Popper", 234567},
	{"Sasaki Seiji", 51994582},
	{"Bertrand Arthur William Russell", 345678}
};


list<Entry> phone_book_lst = {
	{"David Hume", 123456},
	{"Sasaki Seiji", 7525790},
	{"Karl Popper", 234567},
	{"Sasaki Seiji", 51994582},
	{"Bertrand Arthur William Russell", 345678}
};

// 2016.04.02 add
template<typename C>
void print_book(const C& book)
{
	for (const auto& x : book)
		cout << x << '\n';
}

int main()
{
	vector<Entry> phone_book_vec2 = phone_book_vec;

	cout << "before call f(), phone_book_vec:\n";
	print_book(phone_book_vec);

	f(phone_book_vec, phone_book_lst);
	cout << "after call f(), phone_book_vec:\n";
	print_book(phone_book_vec);
	cout << "and phone_book_lst:\n";
	print_book(phone_book_lst);

	list<Entry> phone_book_lst2 = f2(phone_book_vec2);
	cout << "after call f2(), phone_book_lst2:\n";
	print_book(phone_book_lst2);
}
