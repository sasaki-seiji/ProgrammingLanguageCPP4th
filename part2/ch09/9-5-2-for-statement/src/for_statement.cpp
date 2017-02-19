/*
 * for_statement.cpp
 *
 *  Created on: 2016/04/24
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
#include "unistd.h"
using namespace std;

void f(int v[], int max)
{
	cout << "-- f(int v[], int max) using for --\n";

	for (int i = 0; i!=max; ++i)
		v[i] = i*i;
}

void f2(int v[], int max)
{
	cout << "-- f2(int v[], int max) using while --\n";

	int i;
	while (i!=max) {
		v[i] = i*i;
		++i;
	}
}

void input(vector<string>& v)
{
	cout << "-- input(vector<string>&) --\n";

	for (string s; cin >> s; )
		v.push_back(s);
}

template<typename C> void print(C &c)
{
	cout << '[';
	for (auto p = begin(c); p!=end(c); ++p)
		cout << ' ' << *p;
	cout << " ]\n";
}

int main()
{
	const int max = 5;

	int	v[max];
	f(v, max);
	print(v);

	int v2[max];
	f2(v2, max);
	print(v2);

	vector<string> vs;
	input(vs);
	print(vs);

	// forever
	cout << "loop forever...\n";
	for (;;) {
		sleep(1);
	}
}


