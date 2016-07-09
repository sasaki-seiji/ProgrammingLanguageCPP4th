/*
 * file2.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */


struct S { int a; char b; };

#include <iostream>
using namespace std;
void f(S* p)
{ cout << "f({" << p->a << ", '" << p->b << "'}) called\n"; }

#include "s.h"
void f0(S0* p)
{ cout << "f0({" << p->a << ", '" << p->b << "'}) called\n"; }

struct S2 { int a; char bb; };
	// error, but compiler does not detect

typedef char X;
struct S3 { X a; char b; };
	// error, but compiler does not detect

class Point { int x; int y; };
#include "sp.h"
	// error, but compiler does not detect


// add main
int main()
{
	S s = { 100, 'a' };
	f(&s);

	S0 s0 = { 200, 'b' };
	f0(&s0);

	void using_f0(S0 *p);
	using_f0(&s0);
}
