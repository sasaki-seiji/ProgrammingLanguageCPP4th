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

void foo(MyVector<int>&v)
{
	cout << v << endl;;
}

