/*
 * pointer_and_reference_conversion.cpp
 *
 *  Created on: 2016/04/29
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

int* p = (1+2)*(2*(1-1));

int i;
void* vpi = &i;
void f(){ }
//void* vpf = f;
	// error: invalid conversion from 'void (*)()' to 'void*' [-fpermissive]

int main()
{
	cout << "p: " << p << '\n';
	cout << "vpi: " << vpi << '\n';
}

