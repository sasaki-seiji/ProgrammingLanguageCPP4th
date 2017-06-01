/*
 * extern_template.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */


#include "MyVector.h"
#include <iostream>
using namespace std;

extern template class MyVector<int>;

void f(MyVector<int>&v)
{
	cout << v << endl;;
}

