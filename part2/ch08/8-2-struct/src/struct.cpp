/*
 * struct.cpp
 *
 *  Created on: 2016/04/17
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct Address {
	const char*	name;
	int	number;
	const char*	street;
	const char*	town;
	char state[2];
	const char*	zip;
};

void print_addr(const Address* p);
void print_addr2(const Address& r);

void f()
{
	cout << "-- f() --\n";

	Address jd;
	jd.name = "Jim Dandy";
	jd.number = 61;

	// 2017.02.15 add
	print_addr(&jd);
}

void print_addr(const Address* p)
{
	cout << "-- print_addr(const Address*) --\n";

	cout << p->name << '\n'
			<< p->number << ' ' << p->street << '\n'
			<< p->town << '\n'
			<< p->state[0] << p->state[1] << ' ' << p->zip << '\n';
}

void print_addr2(const Address& r)
{
	cout << "-- print_addr2(const Address&) --\n";

	cout << r.name << '\n'
			<< r.number << ' ' << r.street << '\n'
			<< r.town << '\n'
			<< r.state[0] << r.state[1] << ' ' << r.zip << '\n';
}

Address current;
Address set_current(Address next)
{
	cout << "-- set_current(Address) --\n";

	Address prev = current;
	current = next;
	return prev;
}

int main()
{
	f();

	Address jd = {
		"Jim Dandy",
		61, "South St",
		"New Providence",
		{'N', 'J'}, "07974"
	};
	print_addr(&jd);
	print_addr2(jd);

	Address other = {
		"XXX YYYY",
		100, "ZZZZ",
		"WWW WWWWW",
		{'C', 'A'}, "01234"
	};
	current = jd;
	Address prev = set_current(other);

	cout << "current:\n";
	print_addr(&current);
	cout << "prev:\n";
	print_addr(&prev);
}

