/*
 * pointer_ownership.cpp
 *
 *  Created on: 2016/04/16
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void confused(int* p)
{
	// delete p ?
}

int global {7};

void f()
{
	int* pn = new int{7}; //reak
	int i {7};
	int* q = &i;
	confused(pn);
	confused(q);
	confused(&global);
}

int main()
{
	f();
}

