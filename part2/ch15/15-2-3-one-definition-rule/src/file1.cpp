/*
 * file1.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */


struct S { int a; char b; };
void f(S*);

#include "s.h"
void using_f0(S0 *p) { f0(p); }

struct S1 { int a; char b; };
//struct S1 { int a; char b; };
	// error: previous definition of 'struct S1'

struct S2 { int a; char b; };

typedef int X;
struct S3 { X a; char b; };

#define Point int
#include "sp.h"
