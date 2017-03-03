/*
 * function_definition.cpp
 *
 *  Created on: 2016/05/04
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void swap(int*, int*);

void swap(int* p, int* q)
{
	int t = *p;
	*p = *q;
	*q = t;
}

void f(int);
void f(const int);

void f(int x) { cout << "f(int: " << x << ")\n"; ++x; }
//void f(const int x) { cout << "f(const int: " << x << ")\n"; }
	// error: redefinition of 'void f(int)'

int& max(int& a, int& b, int& c);
int& max(int& x1, int& x2, int& x3)
{
	return (x1>x2) ? ((x1>x3)?x1:x3) : ((x2>x3)?x2:x3);
}

struct table { };
void search(table* t, const char* key, const char*)
{
	cout << "-- search(table* t,const char* key, const char*) --\n";

	cout << "t = " << t << '\n';
	cout << "key = " << key << '\n';
}

int main()
{
	int i = 10, j = 20;

	cout << "before swap(), i = " << i << ", j = " << j << '\n';
	swap(&i, &j);
	cout << "after swap(), i = " << i << ", j = " << j << '\n';

	f(i);

	int k = 30;
	cout << "before max()++, i,j,k = " << i << ',' << j << ',' << k << endl;
	max(i,j,k)++;
	cout << "after max()++, i,j,k = " << i << ',' << j << ',' << k << endl;

	table t;
	search(&t, "search-key", nullptr);
}

