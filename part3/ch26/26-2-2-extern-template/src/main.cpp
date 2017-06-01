/*
 * main.cpp
 *
 *  Created on: 2017/06/01
 *      Author: sasaki
 */


#include "MyVector.h"

extern template class MyVector<int>;

void foo(MyVector<int>&v);

void bar(MyVector<int>& v);

// add main

int main()
{
	MyVector<int> vi{10,11,12,13,14,15};
	foo(vi);
	bar(vi);
	foo(vi);
}


