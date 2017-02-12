/*
 * array_operation.cpp
 *
 *  Created on: 2016/04/15
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void use(char c)
{
	cout << c << ":" << int{c} << '\n';
}

void fi(char v[])
{
	cout << "-- fi(" << v << ") --\n";

	for (int i = 0; v[i] != 0; ++i)
		use(v[i]);
}

void fp(char v[])
{
	cout << "-- fp(" << v << ") --\n";

	for (char* p = v; *p != 0; ++p)
		use(*p);
}

template<typename T>
int byte_diff(T* p, T* q)
{
	return reinterpret_cast<char*>(q) - reinterpret_cast<char*>(p);
}

void diff_test()
{
	cout << "-- diff_test() --\n";

	int vi[10];
	short vs[10];
	cout << vi << ' ' << &vi[1] << ' ' << &vi[1] - &vi[0] << ' '
			<< byte_diff(&vi[0], &vi[1]) << '\n';
	cout << vs << ' ' << &vs[1] << ' ' << &vs[1] - &vs[0] << ' '
			<< byte_diff(&vs[0], &vs[1]) << '\n';
}

void f()
{
	cout << "-- f() --\n";

	int v1[10];
	int v2[10];

	int i1 = &v1[5]-&v1[3];
	int i2 = &v1[5]-&v2[3];

	int* p1 = v2+2;
	int* p2 = v2-2;

	cout << "v1 = " << v1 << '\n';
	cout << "v2 = " << v2 << '\n';
	cout << "i1 = " << i1 << '\n';
	cout << "i2 = " << i2 << '\n';
	cout << "p1 = " << p1 << '\n';
	cout << "p2 = " << p2 << '\n';
}

void fp(char v[], int size)
{
	cout << "-- fp(" << v << ", " << size << ") --\n";

	cout << "v[] using size:\n";
	for (int i=0; i!=size; ++i)
		use(v[i]);
	//for (int x : v)
		//use(x);
		// 'begin' was not declared in this scope
		// 'end' was not declared in this scope

	const int N = 7;
	char v2[N];

	cout << "v2[] using size:\n";
	for (int i=0; i!=N; ++i)
		use(v2[i]);

	cout << "v2[] using range for:\n";
	for (int x : v2)
		use(x);
}

int main()
{
	char a[] = "string";
	fi(a);
	fp(a);

	cout << "a[1] == 1[a] ? " << (a[1] == 1[a]) << '\n';

	diff_test();

	f();

	char b[] = { 'a', 'b', 'c' };
	fp(b, sizeof(b));
}


