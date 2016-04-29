/*
 * allocate_array.cpp
 *
 *  Created on: 2016/04/29
 *      Author: sasaki
 */

#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

char* save_string(const char* p)
{
	char* s = new char[strlen(p)+1];
	strcpy(s, p);
	return s;
}

string save_string2(const char* p)
{
	return string{p};
}

void f(int n)
{
	vector<int>*p = new vector<int>(n);
	int *q = new int[n];

	for (int i = 0; i < n; ++i) {
		(*p)[i] = i;
		q[i] = i;
	}

	delete p;
	delete[] q;
}

struct X {
	~X() { cout << "X::~X() is called\n"; }
};
void f1()
{
	X *p = new X;

	delete p;
}

void f2()
{
	X x;
}

int main(int argc, char* argv[])
{
	if (argc < 2) exit(1);

	char *p = save_string(argv[1]);
	cout << "p: " << p << '\n';
	delete[] p;

	string s = save_string2(argv[1]);
	cout << "s: " << s << '\n';

	f(100);

	f1();
	f2();
}

