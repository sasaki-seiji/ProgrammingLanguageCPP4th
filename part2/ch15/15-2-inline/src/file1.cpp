/*
 * file1.cpp
 *
 *  Created on: 2016/07/09
 *      Author: sasaki
 */


inline int f(int i) { return i; }

extern inline int g(int i);
int h(int i) { return g(i); }
	//undefined reference to `g(int)'
	//2017.03.23: OK in g++ 5.4.0 on Ubuntu

#include "h.h"
int h2(int i) { return next(i); }
