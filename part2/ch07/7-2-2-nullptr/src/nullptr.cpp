/*
 * nullptr.cpp
 *
 *  Created on: 2016/04/13
 *      Author: sasaki
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int* pi = nullptr;
double* pd = nullptr;
//int i = nullptr;
	// error: cannot convert ‘std::nullptr_t’ to ‘int’ in initialization

int* x = 0;

int* p = NULL;

int main()
{
	cout << "pi = " << pi << endl;
	cout << "pd = " << pd << endl;
	cout << "x = " << x << endl;
	cout << "p = " << p << endl;
}
