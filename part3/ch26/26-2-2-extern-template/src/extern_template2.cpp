/*
 * extern_template2.cpp
 *
 *  Created on: 2017/06/01
 *      Author: sasaki
 */


#include "MyVector.h"
using namespace std;

extern template class MyVector<int>;

void bar(MyVector<int>& v)
{
	for (size_t i=0; i!=v.size(); ++i)
		v[i] += 10;
}

