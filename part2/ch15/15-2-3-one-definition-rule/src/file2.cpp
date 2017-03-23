/*
 * file2.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct S { int a; char b; };
void f(S* p)
{ cout << "file2.f({" << p->a << ", '" << p->b << "'})\n"; }

#include "s.h"
void f0(S0* p)
{ cout << "file2.f0({" << p->a << ", '" << p->b << "'})\n"; }

struct S2 { int a; char bb; };
	// error, but compiler does not detect
void f2(S2* p)
{ cout << "file2.f2({" << p->a << ", '" << p->bb << "'})\n"; }

typedef char X;
struct S3 { X a; char b; };
	// error, but compiler does not detect
void f3(S3* p)
{ cout << "file2.f3({'" << p->a << "', '" << p->b << "'})\n"; }

struct Point { int x; int y; };
#include "sp.h"
	// error, but compiler does not detect
void fp(SP* p)
{ cout << "file2.fp({(" << p->a.x << ", " << p->a.y << "), '" << p->b << "'})\n"; }

void print_file1();
void print_file2()
{
	cout << "-- print_file1() --\n";

	S s = { 100, 'a' };
	f(&s);

	S0 s0 = { 200, 'b' };
	f0(&s0);

	S2 s2 = { 200, 'c' };
	f2(&s2);

	S3 s3 = { 80, 'd' };
	f3(&s3);

	SP sp = { Point{1,2}, 'x' };
	fp(&sp);
}

// add main
int main()
{
	print_file1();
	print_file2();
}
