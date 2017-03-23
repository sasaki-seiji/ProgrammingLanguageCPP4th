/*
 * file1.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */

#include <iostream>
using namespace std;


struct S { int a; char b; };
void f(S*);

#include "s.h"

struct S1 { int a; char b; };
//struct S1 { int a; char b; };
	// error: previous definition of 'struct S1'

struct S2 { int a; char b; };
void f2(S2*);

typedef int X;
struct S3 { X a; char b; };
void f3(S3*);

#define Point int
#include "sp.h"
void fp(SP*);

void print_file1()
{
	cout << "-- print_file2() --\n";

	S s = { 100, 'a' };
	f(&s);

	S0 s0 = { 200, 'b' };
	f0(&s0);

	S2 s2 = { 200, 'c' };
	f2(&s2);

	S3 s3 = { 80, 'd' };
	f3(&s3);

	SP sp = { 100, 'x' };
	fp(&sp);
}
