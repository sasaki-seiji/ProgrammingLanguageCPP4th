/*
 * if_statement.cpp
 *
 *  Created on: 2016/04/23
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void test(int x, const void* p)
{
	if (x) { cout << "hit if(x): x == " << x << "\n"; }
	if (p) { cout << "hit if(p): p == " << p << "\n"; }
}

enum E1 {a, b };
enum class E2 { a, b };

void f(E1 x, E2 y)
{
	if (x) { cout << "hit if(x): x == " << x << '\n';}
	//if (y) { }
		// could not convert 'y' from 'E2' to 'bool'
	if (y == E2::a) { cout << "hit if(y == E2::a)\n";}
}

struct S {
	int count;
};

void g(S* p)
{
	if (p && 1 < p->count) {
		cout << "hit if(p && 1 < p->count): p == " << p << '\n';
	}
}

int max(int a, int b)
{
	return (a>b)?a:b;
}

void f2(int i)
{
	if (i){
		int x = i+2;
		++x;
	}
	else {
		//++x;
			// 	'x' was not declared in this scope
	}
	//++x;
		// 'x' was not declared in this scope
}

void f1(int i)
{
	if (i)
		int x = i+2;
			// unused variable 'x' [-Wunused-variable]
}

int main()
{
	test(0, "string");
	test(10, nullptr);

	f(a, E2::a);
	f(b, E2::b);

	S s = {2};
	g(&s);

	cout << "max(2,3) returns " << max(2,3) << '\n';

	f1(10);
}

