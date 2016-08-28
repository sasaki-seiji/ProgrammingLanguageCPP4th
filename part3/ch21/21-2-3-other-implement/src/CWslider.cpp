/*
 * CWslider.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "CWslider.h"
#include <iostream>
using namespace std;

CWslider::CWslider(int ll, int hh)
	: val{ll}, low{ll}, high{hh}, changed{false}
{
}

void CWslider::prompt(const char* name)
{
	cout << "Enter value into " << name << ": " << flush ;

	int v;
	cin >> v;
	set_value(v);
}

