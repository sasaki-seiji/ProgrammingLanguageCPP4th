/*
 * BBslider.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "BBslider.h"
#include <iostream>
using namespace std;

BBslider::BBslider(int ll, int hh)
	:val{ll}, low{ll}, high{hh}, changed{false}
{
}

void BBslider::prompt(const char* name)
{
	cout << "enter value into " << name << ": " << flush ;

	int v;
	cin >> v;
	value(v);
}

void BBslider::incr()
{
	int old = value();
	value(old+1);
}
void BBslider::decr()
{
	int old = value();
	value(old-1);

}
