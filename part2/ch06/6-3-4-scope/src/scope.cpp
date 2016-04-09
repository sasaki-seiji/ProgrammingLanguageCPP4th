/*
 * scope.cpp
 *
 *  Created on: 2016/04/09
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int x;
void f()
{
	int x;
	x = 1;
	{
		int x;
		x = 2;
		cout << "x = " << x << '\n';
	}
	x = 3;

	cout << "x = " << x << '\n';
}
int *p = &x;

void f2()
{
	int x = 1;
	::x = 2;
	x = 2;
	cout << "x = " << x << '\n';
	cout << "::x = " << ::x << '\n';
}

void f3()
{
	int x = x;	// 'x' is used uninitialized in this function [-Wuninitialized]

	cout << "x = " << x << '\n';
}

void f4()
{
	int y = x;	// x means ::x
	int x = 22;
	y = x;		// x means local x

	cout << "x = " << x << '\n';
	cout << "y = " << y << '\n';
}

void f5(int x)
{
	//int x;
	// Invalid redeclaration of 'x'
}

void f(vector<string>& v, list<int>& lst)
{
	for (const auto& x : v) cout << x << '\n';
	for (auto x : lst) cout << x << '\n';
	for (int i = 0; i != v.size(); ++i) cout << v[i] << '\n';
	for (auto i : {1, 2, 3, 4, 5, 6, 7}) cout << i << '\n';
}

int main()
{
	f();
	f2();
	f3();
	f4();

	vector<string> v = { "this", "is", "a", "string", "vector"};
	list<int> lst = { 5, 4, 3, 2, 1};
	f(v, lst);
}

