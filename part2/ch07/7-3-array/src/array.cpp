/*
 * array.cpp
 *
 *  Created on: 2016/04/13
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

float v[3];
char* a[32];

void f()
{
	int aa[10];
	aa[6] = 9;
	int x = aa[99];

	cout << "x = " << x << '\n';
}

void f(int n)
{
	int v1[n];
	vector<int> v2(n);

	cout << "v1[0] = " << v1[0] << '\n';
	cout << "v2[0] = " << v2[0] << '\n';
}

int a1[10];

void f2()
{
	int a2[20];
	int *p = new int[40];

	cout << "a1[0] = " << a1[0] << '\n';
	cout << "a2[0] = " << a2[0] << '\n';
	cout << "p[0] = " << p[0] << '\n';
}

int main()
{
	f();
	f(10);
	f2();
}
