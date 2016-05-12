/*
 * array_argument.cpp
 *
 *  Created on: 2016/05/05
 *      Author: sasaki
 */

#include <cstring>
#include <iostream>
using namespace std;

void f()
{
	char v[] = "Annemarie";
	int i = strlen(v);
	int j = strlen("Nicholas");

	cout << "i: " << i << '\n';
	cout << "j: " << j << '\n';
}

void odd(int* p);
void odd(int a[]);
void odd(int buf[1020]);

void f(int(&r)[4])
{
	cout << "[ ";
	for (int i = 0; i != 4; ++i)
		cout << r[i] << ' ';
	cout << "]\n";
}

void g()
{
	int a1[] = {1,2,3,4};
	int a2[] = {1,2};

	f(a1);
	// f(a2);
		// no matching function for call to 'f(int [2])'
}

template<typename T, int N> void f(T(&r)[N])
{
	cout << "[ ";
	for (int i = 0; i != N; ++i)
		cout << r[i] << ' ';
	cout << "]\n";
}

int a1[10];
double a2[100];

void g2()
{
	f(a1);
	f(a2);
}

int main()
{
	f();
	g();

	for (int i = 0; i != 10; ++i) a1[i] = i;
	for (int i = 0; i != 100; ++i) a2[i] = i*0.1;
	g2();
}

