/*
 * Action.cpp
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */

#include "Action.h"

int Action::operator()(int x)
{
	return x;
}
pair<int,int> Action::operator()(int x,int y)
{
	return pair<int, int>(x, y);
}
double Action::operator()(double x)
{
	return x;
}
